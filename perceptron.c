#include <stdio.h>

struct bin {
	float inp[2];
	float ans;
};

int main(void) {
	struct bin data[4] = { { { 0.0, 0.0 }, 0.0 },
						{ { 0.0, 1.0 }, 0.0 },
						{ { 1.0, 0.0 }, 0.0 },
						{ { 1.0, 1.0 }, 1.0 } };
	
	float alpha = 0.01;
	float bias = 0.0;
	float weights[2] = { 0.0, 0.0 };
	
	float result;
	float y[4];
	int tf = 1;


	while(1) {
		for(int i = 0; i < 4; i++) {
			result = (weights[0] * data[i].inp[0] + weights[1] * data[i].inp[1] + bias) > 0;
			result = (float)result;
			y[i] = result;
			if(result != data[i].ans) {
				for(int j = 0; j < 2; j++) {
					weights[j] += alpha * (data[i].ans - result) * data[i].inp[j];
				}
				bias += alpha * (data[i].ans - result);
				break;
			}
		}
		for(int i = 0; i < 4; i++) {
			if(y[i] != data[i].ans) {
				tf = 0;
			}
		}
		if(tf) {
			printf("%f %f %f\n", weights[0], weights[1], bias);
			return 0;
		}
		tf = 1;
	}
	return 0;
}
