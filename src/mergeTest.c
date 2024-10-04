#include"xparameters.h"
#include "xil_io.h"


int main(){
	u32 a[] = {1,5,6,9,16,25,32};
	u32 b[] = {3,5,7,10,12,20};
	u32 c[13];
	u32 Status;

	for(int i=0;i<7;i++){
		Xil_Out32(XPAR_MERGE_V1_0_0_BASEADDR+0xC,a[i]);
	}

	for(int i=0;i<6;i++){
		Xil_Out32(XPAR_MERGE_V1_0_0_BASEADDR+0x10,b[i]);
	}

	Xil_Out32(XPAR_MERGE_V1_0_0_BASEADDR,0x1);

	Status = Xil_In32(XPAR_MERGE_V1_0_0_BASEADDR+4);

	while(!Status)
		Status = Xil_In32(XPAR_MERGE_V1_0_0_BASEADDR+4);

	for(int i=0;i<13;i++){
		c[i] = Xil_In32(XPAR_MERGE_V1_0_0_BASEADDR+0x8);
		xil_printf("%d\n\r",c[i]);
	}

	return 0;
}


