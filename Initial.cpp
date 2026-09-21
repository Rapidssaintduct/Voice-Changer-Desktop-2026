#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Employee {
public:
    Employee(const std::string& name, int hoursWorked, double hourlyRate)
        : name(name), hoursWorked(hoursWorked), hourlyRate(hourlyRate) {}

    const std::string& getName() const {
        return name;
    }

    double salary() const {
        return hoursWorked * hourlyRate;
    }

private:
    std::string name;
    int hoursWorked;
    double hourlyRate;
};

class Payroll {
public:
    void addEmployee(const std::string& name, int hoursWorked, double hourlyRate) {
        employees.emplace_back(name, hoursWorked, hourlyRate);
    }

    void printPayroll() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Payroll Report\n";
        std::cout << "==============\n";

        double total = 0.0;

        for (const auto& employee : employees) {
            double pay = employee.salary();
            std::cout << employee.getName() << " : $" << pay << std::endl;
            total += pay;
        }

        std::cout << "==============\n";
        std::cout << "Total Payroll: $" << total << std::endl;
    }

private:
    std::vector<Employee> employees;
};

int main() {
    Payroll payroll;

    payroll.addEmployee("Alice", 160, 32.50);
    payroll.addEmployee("Brian", 152, 28.75);
    payroll.addEmployee("Clara", 168, 35.20);
    payroll.addEmployee("David", 145, 30.10);

    payroll.printPayroll();

    return 0;
}
