#include <cstring>
#include <vector>
#include <map>
#include "string"
#include "CNumber.h"
#include "CalculatorError.h"

using namespace std;

void initializeApp();
bool findIn(vector<string> data, const string& toFind);
bool findIn(vector<string> data, const char & toFind);
bool findIn(vector<int> data, const int & toFind);
int findLastIndex(const string& basicString, int fromIndex,const string& toFind, int repetitions);
std::string extractSubstring(string basicString,int initialPos,char leftDelimeter,char rightDelimeter);
std::vector<std::string> extractParams(string basicString);
std::string validateSyntax(const string &basicString);
string validateScope(const string &basicString);
string validateSymbols(const string &basicString);string detectANumberWithoutSign(const string &basicString, int initialPos,CalculatorError calculatorError);
std::string fixUp(const string &basicString,const CalculatorError& stackError);
void * evaluateFile(void * _path);

CNumber * computeExpression(string &basicString,CalculatorError stackError=CalculatorError());
CNumber * executeParametrizedFun(const string& functionName, string sublevel,const std::map<string,CNumber>& adresses,CalculatorError stackError=CalculatorError());
CNumber * executeNormalOperation(const string &functionName, vector<string> params, const std::map<string, CNumber>& adresses,CalculatorError stackError=CalculatorError());
vector<string> &replaceMemoryAdress(vector<string> &params, const map<string, CNumber> &adresses, CalculatorError &stackError, const vector<int>& dontCompute=vector<int>());