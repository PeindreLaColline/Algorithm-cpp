/*15:00*/
#include <iostream>
#include <string>
using namespace std;

int a, b, c;

string get_type(int num){
    if(num%15 == 0){
        return "FizzBuzz";
    }
    else if(num %3 == 0){
        return "Fizz";
    }
    else if(num %5 == 0){
        return "Buzz";
    }
    else{
        return "num";
    }
}

int type_check(string s){
    if(s == "FizzBuzz") return -15;
    else if(s == "Fizz") return -3;
    else if(s == "Buzz") return -5;
    else{
        int num = 0;
        for(int i =0; i<s.size(); i++){
            num+= (s[i] -'0');
            num*=10;
        }
        return num/10;
    }
}

int main(){
    string atmp, btmp, ctmp;
    
    cin >> atmp;
    a = type_check(atmp);

    cin >> btmp;
    b = type_check(btmp);

    cin >> ctmp;
    c = type_check(ctmp);

    if(a>0){
        string s = get_type(a+3);
        if(s == "num"){
            cout << a+3;
        }
        else{
            cout << s;
        }
    }
    else if(b>0){
        string s = get_type(b+2);
        if(s == "num"){
            cout << b+2;
        }
        else{
            cout << s;
        }
    }
    else if(c>0){
        string s = get_type(c+1);
        if(s == "num"){
            cout << c+1;
        }
        else{
            cout << s;
        }
    }
    else{
        if(a==-15){
            int aa = 15;
            int bb, cc;
            while(true){
                bb = aa+1;
                cc = aa+2;
                if(get_type(bb) == btmp){
                    if(get_type(cc) == ctmp){
                        string s = get_type(cc+1);
                        if(s=="num"){
                            cout << cc+1;
                        }
                        else{
                            cout <<s;
                        }
                        break;
                    }
                }
                aa+=15;
            }
        }
        else if(a==-5){
            int aa = 5;
            int bb, cc;
            while(true){
                bb = aa+1;
                cc = aa+2;
                if(get_type(bb) == btmp){
                    if(get_type(cc) == ctmp){
                        string s = get_type(cc+1);
                        if(s=="num"){
                            cout << cc+1;
                        }
                        else{
                            cout <<s;
                        }
                        break;
                    }
                }
                aa+=5;
            }
        }
        else if(a==-3){
            int aa = 3;
            int bb, cc;
            while(true){
                bb = aa+1;
                cc = aa+2;
                if(get_type(bb) == btmp){
                    if(get_type(cc) == ctmp){
                        string s = get_type(cc+1);
                        if(s=="num"){
                            cout << cc+1;
                        }
                        else{
                            cout <<s;
                        }
                        break;
                    }
                }
                aa+=3;
            }
        }
    }


    // cout << a<<endl;
    // cout << b<<endl;
    // cout << c<<endl;
}