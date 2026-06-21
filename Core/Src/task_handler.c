
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "main.h"

unsigned int iVar = 56;
state_t curr_state;


void process_command(command_t *cmd){
	const uint8_t pvBuffer;

	int i;


	/*extract the data bytes from the input data queue and form a command */

	command_t cmd;
	cmd.len =0;

	for ( i=0 ; i<10 ; i++)
	{

		xQueueReceive(q_data, &pvBuffer , 10);
		if(pvBuffer != '\n'){

			cmd.payload[i] = pvBuffer;
			cmd.len ++;

		}
		else return;


	}




	//extract_command(cmd);



	switch(curr_state){
	case sMainMenu :
		/* notify the menu task with cmd*/
		xTaskNotify( menu_task_h,0 ,eNoAction );
		break;

	case sLedEffect:
		/* notify the led effect task with cmd*/
		xTaskNotify( led_task_h,0 ,eNoAction );
		break;


	case sRtcMenu:
		break;
	case sRtcDateConfig:
		break;
	case sRtcDateConfig:
		break;
	case sRtcReport:
		/* notify the rtc task with cmd*/
		xTaskNotify( rtc_task_h,0 ,eNoAction );
		break;

	}

}


void cmd_task (void * params ){

	command_t *cmd;

	for(;;){
		/* implement notify wait*/
	  xTaskNotifyWait( 0,0,NULL, 10 );


		/*process the user data (command ) stored in input data queue
		 * notify the command to relevant task
		 * */
		process_command(cmd);


	}

}

void menu_task (void * params )
{


	for(;;)
	{
//			/*Sending data to the Queue*/
//		if( xQueueSend(xQueue1, (void *)&iVar , (TickType_t)10)
//				!= pdPASS)
//		{
//
//			printf( "T1 NOK Send\n");
//		}
//		else
//		{
//
//			printf( "T1 OK Send \n");
//		}
//	  vTaskDelay(pdMS_TO_TICKS(100));
//	  taskYIELD();
	}

}



void print_task (void * params ){

 unsigned int iVar_r;
	for(;;){

	}

}

void led_task (void * params ){

 unsigned int iVar_r;
	for(;;){

	}

}

void rtc_task (void * params ){

 unsigned int iVar_r;
	for(;;){

	}

}
