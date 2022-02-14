#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;




void reverse_str(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

bool isNumber(char &n)
{
 
    if(!isdigit(n))
    {
        return false;
    }
    else
        return true;
}

int postorder(string postfix)
{
    stack<int> s;
    int temp;
    int result;
    for(int i = 0; i < postfix.size(); i++)
    {
 
        if(isNumber(postfix[i])==true)
        {
            char c = postfix[i];
            temp = c-'0';
            s.push(temp);
        }
        if(postfix[i]=='+')
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            result = x+y;
            s.push(result);
        }
        if(postfix[i]=='-')
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            result = y-x;
            s.push(result);
        }
        if(postfix[i]=='*')
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            result = x*y;
            s.push(result);
        }
    }
    
 
    return s.top();

}

int preorder(string prefix)
{
    stack<int> s;
    int temp;
    int result;
    reverse(prefix.begin(),prefix.end());
 
    for(int i = 0; i < prefix.size(); i++)
    {
 
        if(isNumber(prefix[i])==true)
        {
            char c = prefix[i];
            temp = c-'0';
            s.push(temp);
        }
        if(prefix[i]=='+')
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            result = x+y;
            s.push(result);
        }
        if(prefix[i]=='-')
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            result = x-y;
            s.push(result);
        }
        if(prefix[i]=='*')
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            result = x*y;
            s.push(result);
        }
    }
    
 
    return s.top();
}


int main()
{
    string exp,type;
    cin>>type;
    cin >> exp;
    int res;
    
    if(type=="Preorder"){
        res=preorder(exp);
    }
    else
    {
        res=postorder(exp);
    }
    cout<<endl<<res<<endl;

}