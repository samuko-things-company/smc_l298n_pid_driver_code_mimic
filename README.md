## currently implemented route
**PPR_A**
- set PPR_A value:
  > send("/pprA", pprA_value_in_float)  -  don't forget to send value finally as string. the funtion returns "1" or "0" to indicate if opoeration was successful or not
- get PPR_A value:
  > get("/pprA") - returns PPR_A value as string which you'll convert to float.

**PPR_B**
- set PPR_B value:
  > send("/pprB", pprB_value_in_float)  -  don't forget to send value finally as string. the funtion returns "1" or "0" to indicate if opoeration was successful or not
- get PPR_B value:
  > get("/pprB") - returns PPR_B value as string which you'll convert to float.

**DIR_A**
- set DIR_A value:
  > send("/rdirA", either 1 or -1 [float or int])  -  don't forget to send value finally as string. the funtion returns "1" or "0" to indicate if opoeration was successful or not
- get DIR_A value:
  > get("/rdirA") - returns DIR_A value as string which you'll convert to int and then to [(1)->Forward and (-1)->Reverse].

**DIR_B**
- set DIR_B value:
  > send("/rdirB", either 1 or -1 [float or int])  -  don't forget to send value finally as string. the funtion returns "1" or "0" to indicate if opoeration was successful or not
- get DIR_B value:
  > get("/rdirB") - returns DIR_B value as string which you'll convert to int and then to [(1)->Forward and (-1)->Reverse].

**PWM** (when clicking the **SEND_CMD** button)
- you set PWM value and store in a global variable in the application then use the function below with the **SEND_CMD** button to send the microcontroller.
- generally to send pwm value do this:
  > send("/pwm", pwmA_value_in_int [-255 to +255], pwmB_value_in_int [-255 to +255]) -  don't forget to send value finally as string. the funtion returns "1" or "0" to indicate if opoeration was successful or not
- send PWM_A value:
  > send("/pwm", pwmA_value_in_int [-255 to +255], 0)  -  don't forget to send value finally as string. the funtion returns "1" or "0" to indicate if opoeration was successful or not

**TEST_TIME** (or **DURATION**)
- it is being set in a global variable in the application and not the server code.

Reading **POS(rad)** and **VEL(rad/s)**
- to read that of motorA
  > get("/dataA") : returns in string "motorA_angular_pos,motorA_filtered_angular_speed".
  > seperate the values using the "," delimiter and convert them to float.
  > display the values as **POS(rad)** and **VEL(rad/s)**

- to read that of motorB
  > get("/dataB") : returns in string "motorB_angular_pos,motorb_filtered_angular_speed".
  > seperate the values using the "," delimiter and convert them to float.
  > display the values as **POS(rad)** and **VEL(rad/s)**

The **POS(rad)** data is used with sin and cos to display the virtual motor movement. (we would discuss more of this later)
  > for now you can use the sine data to test the movement.

the **RESET HAND** button is used to reset the hand back to the vertical

```
NOTE: all the `send` fuctions returns "1" or "0" to indicate if opoeration was successful or not
```