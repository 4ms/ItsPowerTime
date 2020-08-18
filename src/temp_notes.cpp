 
//    BSP_LCD_SetFont(&Font20);
//  
//    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"POWER", CENTER_MODE);
//    lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"TIME", CENTER_MODE);
//    wait(1);
//  
//    status = ts.Init(lcd.GetXSize(), lcd.GetYSize());
//  
//    if (status != TS_OK)
//    {
//      lcd.Clear(LCD_COLOR_RED);
//      lcd.SetBackColor(LCD_COLOR_RED);
//      lcd.SetTextColor(LCD_COLOR_WHITE);
//      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN", CENTER_MODE);
//      lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"INIT FAIL", CENTER_MODE);
//    }
//    else
//    {
//      lcd.Clear(LCD_COLOR_WHITE);
//      
//      lcd.SetTextColor(LCD_COLOR_BLUE);
//      lcd.FillRect(79, 82, 100, 100); //(x, y, height, width)
//
//      lcd.SetBackColor(LCD_COLOR_BLUE);
//      lcd.SetTextColor(LCD_COLOR_WHITE);
//      BSP_LCD_SetFont(&Font24);
//      lcd.DisplayStringAt(10, LINE(5), (uint8_t *)"START", CENTER_MODE);
//    }
//    
//    while(1)
//    {
//        //    uint8_t text[30];
////
//////        ts.GetState(&TS_State);      
//////        if (TS_State.TouchDetected)
//////        {
//////            x = TS_State.X;
//////            y = TS_State.Y;
//////            sprintf((char*)text, "x=%d y=%d    ", x, y);
//////            lcd.DisplayStringAt(0, LINE(0), (uint8_t *)&text, LEFT_MODE);
////
//////            wait(0.1);
////        }
//    }