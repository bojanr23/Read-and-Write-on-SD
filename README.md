# Read-and-Write-on-SD

//WRITING VARIABLES FROM SD CARD 32 BIT

main()
{    
    new file_name_2[] = "variables/new_variables_8_bit"; 
    new start_pos = 0;   
    new write_bytes2 = 0;     
    const buf_len2 = 4;
    new data_buffer_2[buf_len2]; 

    // Declare and define new_geofences variable
    new new_geofences = 462; // Replace 12345 with your desired value

    data_buffer_2[0] = (new_geofences & 0xFF);
    data_buffer_2[1] = ((new_geofences >> 8) & 0xFF);
    data_buffer_2[2] = ((new_geofences >> 16) & 0xFF);
    data_buffer_2[3] = ((new_geofences >> 24) & 0xFF);

    write_bytes2 = FileWrite(file_name_2, data_buffer_2, 4, start_pos);
    if (4 == write_bytes2) { // Check Record
        Diagnostics("Success"); 
    } else {
        Diagnostics("Error"); 
    }
}


//READING VARIABLES FROM SD CARD 32 BIT

main()
{    
    new file_name_2[] = "variables/new_variables_8_bit"; 
    new start_pos = 0;   
    new read_bytes2 = 0;     
    const buf_len2 = 4;
    new data_buffer_2[buf_len2]; 

    read_bytes2 = FileRead(file_name_2, data_buffer_2, 4, start_pos);
    if (4 == read_bytes2) {
        new new_geofences = (data_buffer_2[0]) | (data_buffer_2[1] << 8) | (data_buffer_2[2] << 16) | (data_buffer_2[3] << 24);
        Diagnostics("Read new_geofences value: %d", new_geofences);
    } else {
        Diagnostics("Error reading file"); 
    }
}
