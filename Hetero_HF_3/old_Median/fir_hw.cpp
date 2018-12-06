#include "ap_int.h"
#include "ap_fixed.h"

#include "types.h"

#define N 128

const coeff_t coeff_hw[N] = {
		0.00019377747951489474              ,
		-0.00016714269291460805              ,
		-0.00033411459386606938              ,
		-0.00062814413089354315              ,
		-0.0010647215156904329               ,
		-0.0016654539208250424               ,
		-0.0024514208439297466               ,
		-0.0034394651100586211               ,
		-0.0046388842806771025               ,
		-0.0060490522160322902               ,
		-0.0076570048900563049               ,
		-0.0094360193147207793               ,
		-0.011344438842976597                ,
		-0.013325991145968526                ,
		-0.015310226843980482                ,
		-0.017214836876556179                ,
		-0.018948389244849432                ,
		-0.020414841150476811                ,
		-0.021518160408714446                ,
		-0.022168341100572208                ,
		-0.022286697441297194                ,
		-0.021812594035686514                ,
		-0.020708575188591462                ,
		-0.018966235122315402                ,
		-0.016607466963074913                ,
		-0.013689399905673739                ,
		-0.010302781605714732                ,
		-0.0065701511112691777               ,
		-0.0026427487339838272               ,
		 0.0013066417308934335               ,
		 0.0050909648169965849               ,
		 0.0085189895778319293               ,
		 0.011405630876160582                ,
		 0.013583531384296289                ,
		 0.014913892308614854                ,
		 0.015296828660013263                ,
		 0.014680168885287465                ,
		 0.01306601828542835                 ,
		 0.010514611124688395                ,
		 0.0071451003481312024               ,
		 0.0031328136976919163               ,
		-0.0012967859095840127               ,
		-0.0058774148856224773               ,
		-0.01031441426053799                 ,
		-0.014299428978558279                ,
		-0.017526702041618873                ,
		-0.019709907414501009                ,
		-0.020599439244822153                ,
		-0.019997753995285087                ,
		-0.01777269100714958                 ,
		-0.013868413320002118                ,
		-0.0083114490142184565               ,
		-0.0012135697158666703               ,
		 0.0072306839482435435               ,
		 0.016750623906442001                ,
		 0.027010676664354819                ,
		 0.037625251078479451                ,
		 0.048176728692894605                ,
		 0.05823589279256422                 ,
		 0.067382911556361641                ,
		 0.075228663778647009                ,
		 0.081434570456929534                ,
		 0.085729916841622497                ,
		 0.087926008407292394                ,
		 0.087926008407292394                ,
		 0.085729916841622497                ,
		 0.081434570456929534                ,
		 0.075228663778647009                ,
		 0.067382911556361641                ,
		 0.05823589279256422                 ,
		 0.048176728692894605                ,
		 0.037625251078479451                ,
		 0.027010676664354819                ,
		 0.016750623906442001                ,
		 0.0072306839482435435               ,
		-0.0012135697158666703               ,
		-0.0083114490142184565               ,
		-0.013868413320002118                ,
		-0.01777269100714958                 ,
		-0.019997753995285087                ,
		-0.020599439244822153                ,
		-0.019709907414501009                ,
		-0.017526702041618873                ,
		-0.014299428978558279                ,
		-0.01031441426053799                 ,
		-0.0058774148856224773               ,
		-0.0012967859095840127               ,
		 0.0031328136976919163               ,
		 0.0071451003481312024               ,
		 0.010514611124688395                ,
		 0.01306601828542835                 ,
		 0.014680168885287465                ,
		 0.015296828660013263                ,
		 0.014913892308614854                ,
		 0.013583531384296289                ,
		 0.011405630876160582                ,
		 0.0085189895778319293               ,
		 0.0050909648169965849               ,
		 0.0013066417308934335               ,
		-0.0026427487339838272               ,
		-0.0065701511112691777               ,
		-0.010302781605714732                ,
		-0.013689399905673739                ,
		-0.016607466963074913                ,
		-0.018966235122315402                ,
		-0.020708575188591462                ,
		-0.021812594035686514                ,
		-0.022286697441297194                ,
		-0.022168341100572208                ,
		-0.021518160408714446                ,
		-0.020414841150476811                ,
		-0.018948389244849432                ,
		-0.017214836876556179                ,
		-0.015310226843980482                ,
		-0.013325991145968526                ,
		-0.011344438842976597                ,
		-0.0094360193147207793               ,
		-0.0076570048900563049               ,
		-0.0060490522160322902               ,
		-0.0046388842806771025               ,
		-0.0034394651100586211               ,
		-0.0024514208439297466               ,
		-0.0016654539208250424               ,
		-0.0010647215156904329               ,
		-0.00062814413089354315              ,
		-0.00033411459386606938              ,
		-0.00016714269291460805              ,
		 0.00019377747951489474
} ;




void fir_hw(din_t *input, dout_t *res)
{

		static din_t tomb[N];
		accu_t acc=0;

		//*res = 0;

		for_shift: for (int i=N-1; i>0; i--)			// jobbra shitel 0. elem az �j input
		{
			tomb[i] = tomb[i-1];
		}

		tomb[0] = *input;


		for_mac: for (int i=N-1; i>=0; i--)
		{
			acc += coeff_hw[i] * tomb[i];
		}

		*res = acc;

}
