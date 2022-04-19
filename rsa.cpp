#include<iostream>
using namespace std;
long int p,q,n,phi_n,e,d,i,j,c,m,flag;
char oMsg[100];//Original message 
char eMsg[100];//Encrypted message
char dMsg[100];//Decrypted message
bool isPrime=true;
bool prime(long int num){
	for(i=2;i<(num/2);i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
long int calculateD(long int e){
	long int k=1;
	while(1){
		k=k+phi_n;
		if(k%e==0){
			return(k/e);
		}
		
	}
}
void calculateE(){ 
	for(j=2;j<phi_n;j++){
		if(phi_n%j==0)
		continue;
		isPrime=prime(j);
		if(isPrime&&j!=p&&j!=q){
			e=j;
			flag=calculateD(e);
			if(flag>0){
				d=flag;
				break;
			}
		}
		
	}
}
int main(){
	cout<<"Enter p: ";
	cin>>p;
	isPrime=prime(p);
	if(!isPrime){
		cout<<"P is not prime\n";
		exit(1);
	}//input for p
	cout<<"Enter q: ";
	cin>>q;
	isPrime=prime(q);
	if(!isPrime){
		cout<<"Q is not prime\n";
		exit(1);
	}//input for q
	n=p*q;
	phi_n=(p-1)*(q-1);
	calculateE();
	cout<<"Input message:";
	cin>>oMsg;
	cout<<"p\tq\tn\tphi_n\tm"<<endl;
	cout<<p<<"\t"<<q<<"\t"<<n<<"\t"<<phi_n<<"\t"<<oMsg<<"\t"<<endl;
	cout<<"E:"<<e<<endl;
	cout<<"D:"<<d<<endl ;
	int a;
	for(a=0;oMsg[a]!='\0';a++){
	//encryption algorithms
	m=oMsg[a];//convert char to ascii code
	long int k=1;
	for(i=0;i<e;i++){
		k=k*m;
		k=k%n;
	}
	c=k;
	eMsg[a]=c;//convert int to char
	

	//decryption algorithms
	
	 k=1;
	for(i=0;i<d;i++){
		k=k*c;
		k=k%n;
	}
	m=k;
	dMsg[a]=m;//convert int to char

	}
	eMsg[a]=-1;
	dMsg[a]=-1;
	cout<<"The encrypted message is ";
	for(i=0;eMsg[i]!=-1;i++){
		cout<<eMsg[i];
	}
		cout<<"\nThe decrypted message is ";
 for(i=0;dMsg[i]!=-1;i++){
		cout<<dMsg[i];
	}
	cout<<endl;
	return 0;
}
