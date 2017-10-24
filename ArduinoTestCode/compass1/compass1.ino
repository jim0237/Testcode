    #include <Wire.h>
    #include <Adafruit_Sensor.h>
    #include <Adafruit_LSM303_U.h>
     
    /* Assign a unique ID to this sensor at the same time */
    Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);
    
    // You must then add your 'Declination Angle' to the compass, which is the 'Error' of the magnetic field in your location.
    // Find yours here: http://www.magnetic-declination.com/
    // Mine is: 13° 24' E (Positive), which is ~13 Degrees, or (which we need) 0.23 radians
      #define DECLINATION_ANGLE 0.077
    
    // The offset of the mounting position to true north
    // It would be best to run the /examples/magsensor sketch and compare to the compass on your smartphone
      //#define COMPASS_OFFSET 0.0f 
    void setup(void) 
    {
      Serial.begin(115200);
      //Serial.println("Magnetometer Test"); Serial.println("");
      
      /* Initialise the sensor */
      if(!mag.begin())
      {
        /* There was a problem detecting the LSM303 ... check your connections */
        Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
        while(1);
      }
    }
     
    void loop(void) 
    {
      /* Get a new sensor event */ 
      sensors_event_t event; 
      mag.getEvent(&event);
      
      //float Pi = 3.14159;
      
      // Calculate the angle of the vector y,x
      //float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
      float heading = atan2(event.magnetic.y,event.magnetic.x);
      heading += DECLINATION_ANGLE;
      
      // Correcting when signs are reveresed
       if(heading <0) heading += 2*PI;
  
      // correct due to addition of declination for Llano, Tx
        if(heading > 2*PI)heading -= 2*PI;

      heading = heading * 180/PI; // The heading in Degrees unit
      //Serial.print("Compass Heading: ");
      Serial.println(heading);
      delay(200);
    }
