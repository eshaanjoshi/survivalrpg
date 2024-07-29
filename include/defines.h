
#ifndef DEFS
#define DEFS

#define WIDTH 800
#define HEIGHT 600
#define STEP 120
#define FRAME_RATE 60
#define FRAME_DELAY (1000000/FRAME_RATE)
enum ERROR_HANDLER{
	SUCCESS = 0,
	FAIL = 1,
};

typedef enum ERROR_HANDLER state;
#endif