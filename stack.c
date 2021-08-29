#include <string>
#include <stack>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <exception>
#include <unordered_map>
#include <map>

using namespace std;

enum op_codes {
    PUSHZ,
    POP,
    SWAP2,
    SWAP3,
    COPY,
    INC,
    DEC,
    ADD,
    SUB,
    HAVE1,
    HAVE2,
    WHILE,
    EZ,
    GZ
};


struct MyException : public std::exception
{
	const char * what () const throw ()
    {
    	return "C++ Exception";
    }
};

void PrintStack(stack<string> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
 
    string x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}



void split_sentence(const string& str, vector<string>& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));


     //checking for punctuation marks and if found, we remove them from the word
     for(int i = 0, sz = cont.size(); i < sz; i++){
        string word = cont.at(i);
        for(int j = 0, len = word.length(); j < len; j++){
            if(ispunct(word[j])){
                cont.at(i) = word.substr(0, word.length() - 1);
            }
        }
     }
}

void handle_pushz(stack<int>& program_stack)
{
    program_stack.push(0);
}


void hadnle_rte()
{
    try
    {
    	throw MyException();
    }
    catch (MyException& e)
    {
    	std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
}


void handle_pop(stack<int>& program_stack)
{
    cout <<  program_stack.top();
    if(program_stack.size() == 0)
    {
        hadnle_rte();
    }
    program_stack.pop();

}

bool handle_ez(stack<int>& program_stack)
{
    cout << "aici";
    if(program_stack.size() == 0)
    {
        hadnle_rte();
    }
    int elementul_x = program_stack.top();
    if( elementul_x == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

bool handle_gz(stack<int>& program_stack)
{
    if(program_stack.size() == 0)
    {
        hadnle_rte();
    }
    int elementul_x = program_stack.top();
    if( elementul_x > 0)
    {
        return true;
    }
    else{
        return false;
    }

}


typedef bool (*fn)( stack<int>& program_stack);
static fn funcs[] = { handle_gz, handle_ez };

std::map<string, int> my_map = {
    { "GZ", 0 },
    { "EZ", 1 },
};

typedef void (*fnz)( stack<int>& program_stack);

static fnz funcsz[] = {  handle_pop };


std::map<string, int> my_map_special = {
    { "handle_pop", 0 },
};

void handle_loop(stack<int>& program_stack,vector<string>& params,vector<string>&param_while)
{
    int counter = 0;
    bool negate_condition;
    if(program_stack.size() == 0)
    {
        hadnle_rte();
    }

    
    if(params[1] == "NOT")
    {
        negate_condition = true;
    }
    if(negate_condition)
    {
        while ( ! ( funcs[ my_map[ params[ 2 ]  ]  ](program_stack) ) )
        {
            
            funcsz[ my_map_special[ params[ counter ]  ]  ](program_stack);
            counter +=1;
            if(counter > 1)
            {
                counter = 0;
            }
        }
    }
    else{
         while (  ( funcs[ my_map[ params[ 2 ]  ]  ](program_stack) ) )
        {
            
            funcsz[ my_map_special[ params[ counter ]  ]  ](program_stack);
            counter +=1;
            if(counter > 1)
            {
                counter = 0;
            }
        }

    }

}

op_codes hashit (std::string const& inString,vector<string>& params) {
    if (inString == "PUSHZ") return PUSHZ;
    if (inString == "POP") return POP;
    if (inString == "WHILE") return WHILE;
}





int main()
{
    string Command;

    stack<int> program_stack;
    stack<string> program_stack_comenzi;

    vector<string> params;
    vector<string> param_while;
    int32_t Value, OP1, OP2;
    do{
        std::getline(std::cin, Command);
        split_sentence(Command,params);
        cout.flush();
        cin.clear();
        for(auto &s: params){program_stack_comenzi.push(s);}

        switch((hashit(params[0],params))) {
            case PUSHZ:
                handle_pushz(program_stack);
                break;
            case WHILE: 
            
                if(program_stack_comenzi.top() ==  "DO")
                {
                    cout << "yes";
                    do{
                        std::getline(std::cin, Command);
                        split_sentence(Command,params);
                        for(auto &s: params){program_stack_comenzi.push(s);}
                        if(program_stack_comenzi.top() == "BEGIN")
                        {
                            std::getline(std::cin, Command);
                            split_sentence(Command,params);
                            cout.flush();
                            cin.clear();
                            if(Command == "END")
                            {
                                program_stack_comenzi.push("END");
                                break;
                            }

                            param_while.push_back(Command);
                        }
                    }while(program_stack_comenzi.top() != "END");
                }
                handle_loop(program_stack,params,param_while);
                break;

            default:
                hadnle_rte();
                break;
        }
        params.clear();

    }while(true);
    
    return 0;
}