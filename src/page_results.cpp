#include "page_results.h"
#include "display_wrapper.h"
#include "wav_library.hh"

ResultsPage::ResultsPage() {
  continue_but.rect.x = 60;
  continue_but.rect.y = 200;
  continue_but.rect.width = 120;
  continue_but.rect.height = 80;
  continue_but.rect.radius = 5;
  continue_but.text = "Continue";
  continue_but.fontsize = FONT_SIZE_MED;
  continue_but.text_color = LCD_COLOR_BLACK;
  continue_but.bg_color = LCD_COLOR_YELLOW;
}

FailResultsPage::FailResultsPage() {
  bg_col = LCD_COLOR_RED;
  flash_bg_color = bg_col;
  flash_fg_color = LCD_COLOR_WHITE;
  strcpy(result_string, "FAIL");
}

PassResultsPage::PassResultsPage() {
  bg_col = LCD_COLOR_GREEN;
  flash_bg_color = bg_col;
  flash_fg_color = LCD_COLOR_WHITE;
  strcpy(result_string, "PASS");
}

void ResultsPage::set_results(ResultType *results) { test_results = results; }

void ResultsPage::display() {
  fill_screen(bg_col);
  // todo: display time
  display_flashing();
  continue_but.draw();
}

void ResultsPage::display_flashing() {
  // Flashing PASS/FAIL
  set_fg_color(flash_bg_color);
  fill_rect(0, 0, 240, 50);
  set_bg_color(flash_bg_color);
  set_fg_color(flash_fg_color);
  set_font_size(FONT_SIZE_BIG);
  display_string_centered(1, result_string);
}

void FailResultsPage::display_result(AdcChannels chan) {
  char str[10];
  AdcChannelNames::get_string(chan, str);
  const uint8_t line_height = 20;
  const uint8_t top_margin = 60;
  const uint8_t ypos = (static_cast<uint8_t>(chan) * line_height) + top_margin;
  set_font_size(FONT_SIZE_SMALL);
  set_fg_color(LCD_COLOR_BLACK);
  set_bg_color(bg_col);
  display_string(0, ypos, str, LEFT_MODE);
  if (test_results[chan].passed) {
    set_fg_color(LCD_COLOR_GREEN);
    display_string(85, ypos, "pass", LEFT_MODE);
  } else {
    set_fg_color(LCD_COLOR_BLACK);
    display_float(130, ypos, test_results[chan].failed_value, "=%2.02f",
                  LEFT_MODE);
    display_int(0, ypos, (test_results[chan].fail_time / 1000), "@%ds",
                RIGHT_MODE);
    // display_string(0, ypos, test_results[chan].fail_type_string, RIGHT_MODE);
    display_string(85, ypos, "FAIL", LEFT_MODE);
  }
}

void FailResultsPage::display() {
  ResultsPage::display();

  for (auto chan : {voltage12V, voltage5V, voltageN12V, current12V, current5V,
                    currentN12V}) {
    display_result(chan);
  }
}

void PassResultsPage::display() { ResultsPage::display(); }

void ResultsPage::start() {
  timer.reset();
  timer.start();
  display();
}

void FailResultsPage::start() {
  ResultsPage::start();
  // audio.play_wav(WavLibrary::get_sound(WavLibrary::Fail));
  audio.set_gain(1.5f);
  audio.play_wav_looping(WavFile::chirp_400_200, 8000, 16000.0f);
  sound_playing = true;
}

void PassResultsPage::start() {
  ResultsPage::start();
  audio.set_gain(1.0f);
  audio.play_wav_looping(WavFile::ChordHit_011, 22789, 22050.0f);
  // audio.play_wav_looping(WavFile::dog, 17187, 22010.0f);
  sound_playing = true;
}

void ResultsPage::cleanup() { audio.stop(); }

void ResultsPage::update() {
  if ((timer.read_ms() - timer.last_time_read) > 500) {
    bool invert_screen = (flash_bg_color == bg_col);
    flash_bg_color = invert_screen ? LCD_COLOR_WHITE : bg_col;
    flash_fg_color = invert_screen ? bg_col : LCD_COLOR_WHITE;
    display_flashing();

    timer.last_time_read = timer.read_ms();
  }
  if (sound_playing && timer.read_ms() >= 5000) {
    audio.stop();
    sound_playing = false;
  }
  continue_but.update();
}
