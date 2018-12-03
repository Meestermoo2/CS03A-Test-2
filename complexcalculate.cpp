#include "complexcalculate.h"

void introduction()
{
    using namespace std;
    string border(67, '*');
    cout << border << endl;
    cout << "This Program is called complexCalculate and it is an complexNumber "
            "\nCalculator that that will store up to 26 complex numbers." << endl;
    cout << border << endl;
}

void getInput(std::istream &in, memories &me, std::map<std::string, function> &list, bool &save, bool execute, std::string &savefile)
{ // This will retrieve input from either user or filestream.
    using namespace std;

    string userInput = "", argument = "";

    if (&in == &std::cin)
        cout << "\nCOMMAND: ";
    getline(in, userInput);
    if (userInput.empty())
    {
        std::cout << "SEE YA!" <<std::endl;
        std::exit(1);
    }
     // Using extractor operation, we will parse the first word and take it in as a command
    stringstream user_ss(userInput);
    // Retrieve the first string as a command.
    user_ss >> userInput;
    getline(user_ss, argument);

    if (!savefile.empty()) // Records input, if applicable
        recordFile(savefile, userInput+argument);

    for (unsigned int i = 0; i < userInput.length(); ++i) // Converts everything to uppercase.
        userInput[i] = toupper(userInput[i]);

    if(!argument.empty())
        argument = argument.substr(1);// Get the remaining buffer as an argument.

    if(userInput.length() > 1)
    {
        if(userInput == "EXIT")
        {
            if(save)
            {
                exit("", me);
            }
            else
            {
                exit("1", me);
            }
        }
        if (list.find(userInput) != list.end())
            list[userInput](argument, me); // run the commands using function pointers
        else
            throw INVALID_INPUT; // run the commands using function pointers
        if(userInput == "SAVE")
            save = true;
        else
            save = false;
    }
    else
    {
        //for variables e.g. A=B+C
        argument = cleanAndRead(argument);
        if (argument[0]=='=')
        {
           //for derivative calculator (ex F=~G)
           if (argument[1] == '~')
           {
               list["CONJUGATE"](userInput+=argument, me);
               //calculate conjugate
           }
           //for expresison calculator (ex F=G+H)
           else
           {
               //switch that depends on operator
               switch (argument[2])
               {
               case '+':

                   list["ADD"](userInput+=argument, me);
                   break;
               case '-':
                   list["SUBTRACT"](userInput+=argument, me);
                   break;
               case '*':
                   list["MULTIPLY"](userInput+=argument, me);
                   break;
               case '/':
                   list["DIVIDE"](userInput+=argument, me);
                   break;
               case '^':
                   list["POWER"](userInput+=argument, me);
                   break;
               default:
                   cout << "Error " << endl;
                   exit(1);
               }
           }
        }
        else if(argument[0]=='|')
        {
            //A | B
           list["ORTHOGONAL"](userInput+=argument, me);
        }
    }
}


void let(const std::string &arg, memories &me)
{
        std::stringstream temp;
        std::string index2 = "";
        char index; // Holds first char to be used as index
        char junk; // Will hold '='

        temp << arg;
        while (temp.peek() == ' ')
            temp.get();
        temp >> index;
        while (temp.peek() == ' ')
            temp.get();
            temp>> junk;
        index = toupper(index);
        index2 += index;
        if(index2.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ")<index2.size())
                throw INVALID_INPUT;

        complexNumber b;
        me[index-65] = b; // Sets the destination expression to zero before insertion
        temp >> me[index-65];

        // Displays a successful configuration
        std::cout << std::endl << index << " = "
                  << me[int(index-65)] << std::endl;
}

void magnitude(const std::string &arg, memories &me)
{
    std:: cout << "The magnitude of " << char(arg[0]) << " is equal to "<< me[toupper(arg[0])-65].magnitude() << std::endl;
}
void print(const std::string &arg, memories &me)
{
    std:: cout << arg[0] << " = "<< me[toupper(arg[0])-65] << std::endl;
}

void save(const std::string &arg, memories &me)
{
    std::ofstream out;
    std::ifstream in;
    std::string filename = arg;

    //check for empty argument
    char ans;
    if(filename.find('.') > filename.size())
        filename += ".complex";
    in.open(filename);
    in.close();
    if(in.fail())
        out.open(filename);
    else
    {
        in.clear();
        std::cout<<"That file exists!!"<< std::endl;
        std::cout<<"Do you wish to overwrite it?" << std::endl;
        std::cin >> ans;

        char symbol;
        do
        {
            std::cin.get(symbol);
        } while (symbol != '\n');

        if(ans == 'Y' || ans == 'y')
            out.open(filename);
        else
        {
            std::cout << "You chose not to overwrite." << std::endl;
            return;
        }
    }

    out << me; // Writes to file
    std::cout << "Save successful." << std::endl;

}

void load(const std::string &arg, memories &me)
{
    std::ofstream out;
    std::ifstream in;
    std::string filename = arg;

    // Open with arg name, check to overwrite
    if(filename.find('.') > filename.size())
        filename+= ".complex";
    in.open(filename);
    if((in.fail()))
    {
      std::cout << "The input file does not exist!" << std::endl;
    }
    else
    {
      in >> me;
      std::cout << "The file \"" << filename << "\" was loaded! \n";
    }
    out.close();
    in.close();
}

void exit(const std::string &arg, memories &me)
{
    char ans;
        std::string filename;
        if(!arg.empty())
        {
            std::cout << "Do you wish to save the data to a file? "<<std::endl;
            std::cin >> ans;

            char symbol;
            do
            {
                std::cin.get(symbol);
            } while (symbol != '\n');

            if(ans == 'Y' || ans == 'y')
            {
                std::cout << "What is the name of the file? "<<std::endl;
                getline(std::cin, filename);
                save(filename, me);
                std::cout <<"Thank You!" << std::endl;
                exit(1);
            }
        }
        std::cout << "Thank You!" << std::endl;
        exit(1);
}

void wexit(const std::string &arg, memories &me)
{
    save(arg, me);
    exit(1);
}

void add(const std::string &arg, memories &me)
{
    int index = (arg[0]-65), arg1 = (arg[2]-65), arg2 = (arg[4]-65);
    me[index] = me[arg1] + me[arg2];
    std::cout << std::endl << char(index+65) << "=" << me[index] << std::endl;
}

void subtract(const std::string &arg, memories &me)
{
    int index = (arg[0]-65), arg1 = (arg[2]-65), arg2 = (arg[4]-65);
    me[index] = me[arg1] - me[arg2];
    std::cout << std::endl << char(index+65) << "=" << me[index] << std::endl;
}


void multiply(const std::string &arg, memories &me)
{
    int index = (arg[0]-65), arg1 = (arg[2]-65), arg2 = (arg[4]-65);
    me[index] = me[arg1] * me[arg2];
    std::cout << std::endl << char(index+65) << "=" << me[index] << std::endl;
}

void divide(const std::string &arg, memories &me)
{
    int index = (arg[0]-65), arg1 = (arg[2]-65), arg2 = (arg[4]-65);
    me[index] = me[arg1] / me[arg2];
    std::cout << std::endl << char(index+65) << "=" << me[index] << std::endl;
}

void power(const std::string &arg, memories &me)
{
    int index = (arg[0]-65), arg1 = (arg[2]-65), arg2 = (arg[4]-65);
    me[index] = me[arg1] ^ me[arg2];
    std::cout << std::endl << char(index+65) << "=" << me[index] << std::endl;
}

void orthogonal(const std::string &arg, memories &me)
{
    using namespace std;
    int arg1 = (arg[0]-65), arg2 = (arg[2] - 65);
    mixedNumber mag_arg1, mag_arg2, angle_arg1, angle_arg2, diffOfAngles, dotProduct;

    mag_arg1 = me[arg1].magnitude();
    angle_arg1 = me[arg1].angle();

    mag_arg2 = me[arg2].magnitude();
    angle_arg2 = me[arg2].angle();

    diffOfAngles = angle_arg1.getDouble() - angle_arg2.getDouble();
    //z1 dot z2 = |z1||z2|cos(arg(z1)-arg(z2))

    dotProduct = mag_arg1.abs() * mag_arg2.abs() *round(cos(diffOfAngles.getDouble())*10000)/10000;
    std::cout << "The dot product of these two complex numbers is: " << dotProduct << std::endl;
    if(dotProduct == 0)
        std::cout << "Thus, these two complex numbers are orthogonal" << std::endl;
    else
        std::cout << "Thus, these two complex numbers are not orthogonal" << std::endl;
}

void trig(const std::string &arg, memories &me)
{
    me[toupper(arg[1])-65].polarForm();
}

void conjugate(const std::string &arg, memories &me)
{
    int index = (arg[0]-65), arg1 = (arg[3]-65);
    me[index] = me[arg1].conjugate();
    std::cout << std::endl << char(index+65) << "=" << me[index] << std::endl;
}

void loadFunction(std::map<std::string, function> &list)
{ // This will load up our array of function pointers.
    using namespace std;

    string temp;
    list["LET"] = let;
    list["PRINT"] = print;
    list["SAVE"] = save;
    list["LOAD"] = load;
    list["EXIT"] = exit;
    list["WEXIT"] = wexit;
    list["ADD"] = add;
    list["SUBTRACT"] = subtract;
    list["MULTIPLY"] = multiply;
    list["DIVIDE"] = divide;
    list["POWER"] = power;
    list["ORTHOGONAL"] = orthogonal;
    list["TRIG"] = trig;
    list["CONJUGATE"] = conjugate;
    list["DISPLAY"] = display;
    list["MAGNITUDE"] = magnitude;
}

void display(const std::string &arg, memories &me)
{
    std::cout << std::endl;
    std::cout << me;
    std::cout << std::endl;
}

bool validateCommand(const std::string &arg)
{
    std::string dict = "LET PRINT SAVE LOAD EXIT WEXIT ADD SUBTRACT MULTIPLY DIVIDE POWER ORTHOGONAL TRIG CONJUGATE DISPLAY MAGNITUDE";

       int temp;
       temp = arg.find(dict);
       std::cout << temp;
       if (temp == -1)
           throw INVALID_INPUT;
       else
           std::cout << "\n\napproved command";
}

std::string cleanAndRead(const std::string &arg)
{
    std::string temp = "";
    for (unsigned int i = 0; i < arg.length(); ++i)
    {
        if ((arg[i] != ' '))
        {
            temp += toupper(arg[i]);
        }
    }
    return temp;
}

void recordFile(std::string filename, std::string userInput)
{
    using namespace std;

    ofstream out;
    std::ifstream in;

    if(filename.find('.') > filename.size())
        filename += ".spt";

    out.open(filename,ios_base::app);

    out << userInput << endl;

    out.close();

}



