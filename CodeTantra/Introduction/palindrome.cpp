#include <iostream>
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

using namespace std;

int main() {
	long long int num, rem, sum=0;
    cout << "\nEnter the 'number' to check whether it palindrome or not: ";
	cin >> num;
	
	long long int temp = num;
	
	while(num != 0) {
		rem = num%10;
		sum = (sum*10) + rem;
		num /= 10;
	}
	
	if(temp == sum) {
		cout << "\n\"TRUE\", the number "<<temp<<" is "<<UNDERLINE<<"palindrome"<<CLOSEUNDERLINE<<".\n";
	}
	
	else {
		cout << "\n\"FALSE\", the number "<<temp<<" is "<<UNDERLINE<<"not palindrome"<<CLOSEUNDERLINE<<".\n";
	}

    return 0;
}
