#include <iostream>
#include <string>
using namespace std;

class node{

private:
char val;
node* nextnode;

public:
    void set_val(char v){val = v;}
    void set_next_node(node* nn){nextnode = nn;}

    char getval(){return val;}
    node* get_next_node(){return nextnode;}
};

class stck{

private:
  int siz;
  node* header;

public:

    bool isempty()
    {
        if (header->get_next_node()==NULL) {return true;}
        else {return false;}
    }

void push(char x)
{
    node* newnode = new node();
    newnode->set_val(x);
    newnode->set_next_node(header->get_next_node());
    header->set_next_node(newnode);
    siz++;
}

char pop()
{
    if(!isempty())
        {
            node* dn = header->get_next_node();
            char rc = dn->getval();
            header->set_next_node(dn->get_next_node());
            dn->set_next_node(NULL);
            delete dn;
            siz--;
            return rc;
        }
    else {cout<<"Error: Stack is empty";}
}
char tos()
{
    char rcac = (header->get_next_node())->getval();
    return rcac;
}
~stck(){delete header;}
};


stck mystack;

bool isoperator(char check)
{
if ((check == '+') || (check == '-') || (check == '*') || (check == '/') || (check == '^'))
    {
    return true;
    }
else
    {
    return false;
    }

}

int precedence(char c){
    if (c == '^'){return 3;}
    else if ((c == '*') || (c == '/')){return 2;}
    else if ((c == '+') || (c == '-')){return 1;}
}

string convert(string inf)
{
string postfix;
int i= 0;
for (i = 0; i<inf.length(); i++)
    {
     if (!isoperator(inf[i])){postfix[i] = inf[i];}
     else
        {

        while(!mystack.isempty() && (precedence(mystack.tos()) > precedence(inf[i])))
        {
        postfix[i] = mystack.pop();
        i++;
        }
        if (mystack.isempty() == true){mystack.push(inf[i]);}
        }
    }

while(!mystack.isempty()){
        char a = mystack.pop();
        postfix[i] = a;
        }
    return postfix;
}


#include <iostream>
using namespace std;
int main(){cout<<"Please enter infix: "<<endl;
string infix;
cin>>infix;
string pf = convert(infix);
cout<<endl<<endl<<pf;

return 0;}

