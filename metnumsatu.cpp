#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fungsi(double ex){
	return (2*pow(ex,3))+1;
}

double f_trn(double ex){
	return (6*pow(ex,2));
}

int main(){
	double h,tmp1,tmp2,tmp3,rte=100,ex=2,true_error,approx_error,appback_error=0,rae=0;
	int x,iter=0,significant;
	
	//cout<<"Pilih metode :"<<endl;
	//cout<<"1. FDD"<<endl<<"2. CDD"<<endl<<"3. BDD"<<endl;
	//cin>>x;
//	  if(x == 1){
		cout<<"Metode FDD :"<<endl;
		h=0.25;
		cout<<"Iterasi\t\th\t\tf'(x)\t\tTrue Error\tRTE (%)\t\tSignificant\tAE\t\tRAE (%)"<<endl;
		while(rte>1){
			iter++;
			tmp1 = (fungsi(ex+h)-fungsi(ex))/h;
			true_error = f_trn(ex)-tmp1;
			significant = (int) log10(50/rae);
			if (rae==0) significant = 0;
			approx_error = tmp1-appback_error;
			appback_error = tmp1;
			rte = fabs((f_trn(ex)-tmp1)/f_trn(ex))*100;
			rae = fabs((approx_error/tmp1)*100);
			cout<<fixed<<setprecision(4);
			cout<<iter<<"\t\t"<<h<<"\t\t"<<tmp1<<"\t\t"<<true_error<<"\t\t"<<rte<<"\t\t"<<significant<<"\t\t"<<approx_error<<"\t\t"<<rae<<endl;
			h/=2;
		}
//	}else if(x == 2){
		h=0.25;
		cout<<endl<<"Metode CDD :"<<endl;
		iter=0,appback_error=0,rae=0,rte=100;
		cout<<"Iterasi\t\th\t\tf'(x)\t\tTrue Error\tRTE (%)\t\tSignificant\tAE\t\tRAE (%)"<<endl;
		while(rte > 1){
			iter++;
			tmp2 = (fungsi(ex+h)-fungsi(ex-h))/(2*h);
			true_error = f_trn(ex)-tmp2;
			significant = (int) log10(50/rae);
			if (rae==0) significant = 0;
			approx_error = tmp2-appback_error;
			appback_error = tmp2;
			rte = fabs((f_trn(ex)-tmp2)/f_trn(ex))*100;
			rae = fabs((approx_error/tmp2)*100);
			cout<<fixed<<setprecision(4);
			cout<<iter<<"\t\t"<<h<<"\t\t"<<tmp2<<"\t\t"<<true_error<<"\t\t"<<rte<<"\t\t"<<significant<<"\t\t"<<approx_error<<"\t\t"<<rae<<endl;
			h/=2;
		}
//	}else{
		h=0.25;
		cout<<endl<<"Metode BDD :"<<endl;
		iter=0,appback_error=0,rae=0,rte=100;
		cout<<"Iterasi\t\th\t\tf'(x)\t\tTrue Error\tRTE (%)\t\tSignificant\tAE\t\tRAE (%)"<<endl;
		while(rte > 1){
			iter++;
			tmp3 = (fungsi(ex)-fungsi(ex-h))/h;
			true_error = f_trn(ex)-tmp3;
			significant = (int) log10(50/rae);
			if (rae==0) significant = 0;
			approx_error = tmp3-appback_error;
			appback_error = tmp3;
			rte = fabs((f_trn(ex)-tmp3)/f_trn(ex))*100;
			rae = fabs((approx_error/tmp3)*100);
			cout<<fixed<<setprecision(4);
			cout<<iter<<"\t\t"<<h<<"\t\t"<<tmp3<<"\t\t"<<true_error<<"\t\t"<<rte<<"\t\t"<<significant<<"\t\t"<<approx_error<<"\t\t"<<rae<<endl;
			h/=2;
		}
//	}
}
