#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
bool sortByVal(const pair<string, double> &a, const pair<string, double> &b) { 
    return (a.second < b.second); 
}

class Employee{
    public:
        string id;
        string name;
        string surname;
        string departmentId;
        string position;
};

class HRMS{
    public:
        vector<Employee> employees;
        map <string,string> departmentEmployees;
        map <string, double> salaryEmployees;

        void add(Employee employee, string deparmentId, double salary){
            employees.push_back(employee);
            departmentEmployees.insert(make_pair(employee.id,deparmentId));
            salaryEmployees.insert(make_pair(employee.id,salary));
        }

        void printDepartment(string departmentId){
            map<string, string>::iterator it;
            for(it=departmentEmployees.begin(); it!=departmentEmployees.end(); ++it){
                if(it->second==departmentId)
                    cout << it->first << " => " << it->second << '\n';
            }
        }

        void changeSalary(string employeeId, double salary){
            map<string, double>::iterator it = salaryEmployees.find(employeeId);
            if (it != salaryEmployees.end()){
                it->second=salary;
            }
            else{
                cout << "Employee not found\n";
            }
        }

        void printSalaries(){
             map<string, double>::iterator it;
            for(it=salaryEmployees.begin(); it!=salaryEmployees.end(); ++it){
                Employee tempEmployee=findEmployee(it->first);
                cout << tempEmployee.name << " " << tempEmployee.surname <<  ", id = " << tempEmployee.id << ", department id = "<< tempEmployee.departmentId
                << ", position: "<< tempEmployee.position<<", salary: "<< it->second << '\n';
            }
        }

        void printSalariesSorted(){
            vector<pair<string, double>> vec;
            map<string, double>::iterator it;
            for (it=salaryEmployees.begin(); it!=salaryEmployees.end(); it++) {
                vec.push_back(make_pair(it->first, it->second));
            }
            sort(vec.begin(), vec.end(), sortByVal);
            for (int i = 0; i < vec.size(); i++){
                Employee tempEmployee=findEmployee(vec[i].first);  
                cout << tempEmployee.name << " " << tempEmployee.surname <<  ", id = " << tempEmployee.id << ", department id = "<< tempEmployee.departmentId
                << ", position: "<< tempEmployee.position<<", salary: "<< vec[i].second << '\n';         
	        }
        }
        Employee findEmployee(string employeeId){
            for(Employee n: employees){
                if(n.id==employeeId)
                    return n;
            }
            cout <<"Employee not found\n";
            return Employee();
               
        }

};

int main()

{
    
    Employee JMalware;{
    JMalware.id="JMalware";
    JMalware.name="John";
    JMalware.surname="Malware";
    JMalware.position="Wet leisure assistant";
    JMalware.departmentId="The Useless One";}
    Employee AEquinox;{
    AEquinox.id="AEquinox";
    AEquinox.name="Alexandra";
    AEquinox.surname="Equinox";
    AEquinox.position="Director of first impressions";
    AEquinox.departmentId="The Social One";}
    Employee LWall;{
    LWall.id="LWall";
    LWall.name="Luciana";
    LWall.surname="Wall";
    LWall.position="Beauty therapist";
    LWall.departmentId="The Useless One";}
    Employee NSingh;{
    NSingh.id="NSingh";
    NSingh.name="Nour";
    NSingh.surname="Singh";
    NSingh.position="School meals supervisor";
    NSingh.departmentId="The Food One";}
    Employee APetty;{
    APetty.id="APetty";
    APetty.name="Azaan";
    APetty.surname="Petty";
    APetty.position="Canteen assistant";
    APetty.departmentId="The Food One";}
    Employee SPaine;{
    SPaine.id="SPaine";
    SPaine.name="Sydney";
    SPaine.surname="Paine";
    SPaine.position="Customer happiness specialist";
    SPaine.departmentId="The Social One";}
    Employee DRay;{
    DRay.id="DRay";
    DRay.name="Dawid";
    DRay.surname="Ray";
    DRay.position="Restroom Attendant";
    DRay.departmentId="The Useless One";}
    Employee BQuinn;{
        BQuinn.id="BQuinn";
    BQuinn.name="Bevan";
    BQuinn.surname="Quinn";
    BQuinn.position="Beverage dissemination officer";
    BQuinn.departmentId="The Food One";}
    Employee SBlanchard;{
    SBlanchard.id="SBlanchard";
    SBlanchard.name="Shaan";
    SBlanchard.surname="Blanchard";
    SBlanchard.position="Oyster Floater";
    SBlanchard.departmentId="The Food One";}
    Employee SDalton;{
    SDalton.id="SDalton";
    SDalton.name="Sonia";
    SDalton.surname="Dalton";
    SDalton.position="Creativity Analyst";
    SDalton.departmentId="The Useless One";}
    HRMS Hrms;
    
    Hrms.add(JMalware,JMalware.departmentId,12000);
    Hrms.add(AEquinox,AEquinox.departmentId,24000);
    Hrms.add(LWall,LWall.departmentId,31000);
    Hrms.add(NSingh,NSingh.departmentId,70000);
    Hrms.add(APetty,APetty.departmentId,48000);
    Hrms.add(SPaine,SPaine.departmentId,140000);
    Hrms.add(DRay,DRay.departmentId,12000);
    Hrms.add(BQuinn,BQuinn.departmentId,265000);
    Hrms.add(SBlanchard,SBlanchard.departmentId,1340000);
    Hrms.add(SDalton,SDalton.departmentId,30000);
    cout <<"Printing salaries in random order \n";
    Hrms.printSalaries();
    cout <<"Printing The Useless Department\n";
    Hrms.printDepartment("The Useless One");
    cout <<"Printing The Social Department\n";
    Hrms.printDepartment("The Social One");
    cout <<"Printing The Food Deparment\n";
    Hrms.printDepartment("The Food One");
    cout <<"Chaning salary of "<<DRay.id<<" to 24000\n";
    Hrms.changeSalary(DRay.id,24000);
    cout <<"Printing salaries in sorted order\n";
    Hrms.printSalariesSorted();


}