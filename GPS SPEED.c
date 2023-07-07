
main()
{

    new tmp_get_coordinates_status = GetVar(ARE_COORDINATES_VALID);
    new tmp_get_hdop_value = GetVar(HDOP);


    new tmp_comfort_speed = 0;
    new tmp_abs_speed = 0;
    new tmp_position_validation = -1;

    if(tmp_get_coordinates_status == 1 && tmp_get_hdop_value < 10){

       tmp_comfort_speed = GetVar(SPEED);
       tmp_abs_speed = GetVar(SPEED);
       tmp_position_validation = 1;
    
    }



    SetVar(comfort_speed,tmp_comfort_speed);
    TagWriteValue(0x62,tmp_comfort_speed);

    SetVar(abs_speed,tmp_abs_speed);
    TagWriteValue(0x67,tmp_abs_speed);

    SetVar(position_validation,tmp_position_validation);

    SetVar(rpm,1);
    TagWriteValue(0x64,1);

    TagWriteValue(0x68,0);
    SetVar(mileage,0);

    

}