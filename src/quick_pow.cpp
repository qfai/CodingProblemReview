long long quick_pow(int base,int pow){
	long long sum = 1;
	while (pow > 0) {// exit when pow==0, this didn't solve pow<0 case;
		if (pow & 1 == 1)
			sum *= base;
		base *= base;
		pow >>= 1;
	}
	return sum;
}

float quick_pow(float base,int pow){
	float sum = 1;
	if(pow<0){
		pow=-1*pow;
		base=1/base;
	}
	while (pow > 0) {// exit when pow==0, 
		if (pow & 1 == 1)
			sum *= base;
		base *= base;
		pow >>= 1;
	}
	return sum;
}

float newton_sqrt(float base,int pow){
	const float sigma=0.000001;
	
}