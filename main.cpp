#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define PROGRAMMER_POSITION "programmer"
#define ADMIN_POSITION "admin"
using namespace std;



class Worker {
public:
	enum Position{ADMIN,PROGRAMMER};
private:
	string name;
	Position position;
public:
	Worker(string name, Position position) :name(std::move(name)), position(position) {}

	virtual ~Worker()=default;



    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Worker::name = name;
    }

    Position getPosition() const {
        return position;
    }

    void setPosition(Position position) {
        Worker::position = position;
    }
};

class Proggrammer:public Worker {
	string programmingLanguage;
public:
    Proggrammer(const string &name, string programmingLanguage)
        : Worker(name, Worker::PROGRAMMER), programmingLanguage(std::move(programmingLanguage)) {}

    const string &getProgrammingLanguage() const {
        return programmingLanguage;
    }

    void setProgrammingLanguage(const string &programmingLanguage) {
        Proggrammer::programmingLanguage = programmingLanguage;
    }
};

class Admin:public Worker{
    string operationSystem;
public:
    Admin(const string &name, string operationSystem)
        : Worker(name, Worker::ADMIN),operationSystem(std::move(operationSystem)) {}

    const string &getOperationSystem() const {
        return operationSystem;
    }

    void setOperationSystem(const string &operationSystem) {
        Admin::operationSystem = operationSystem;
    }
};




int main() {

//	vector<shared_ptr<Worker>> workers={
//	        shared_ptr<Worker>(new Admin("Vasia","Linux")),
//            shared_ptr<Worker>(new Proggrammer("Petia","C++")),
//            shared_ptr<Worker>(new Proggrammer("Ivan","Python")),
//            shared_ptr<Worker>(new Proggrammer("Oleg","Ruby")),
//            shared_ptr<Worker>(new Admin("Evgen","Windows"))
//	};
//
//	for(shared_ptr<Worker> w:workers){
//	    cout<<w->getName()<<endl;
//	    cout<<"\tPosition: "<<w->getPosition()<<endl;
//	    if(w->getPosition() == ADMIN_POSITION){
//	        cout<<"\tOS: "<<((Admin*)w.get())->getOperationSystem()<<endl;
//	    }
//        if(w->getPosition() == PROGRAMMER_POSITION){
//            cout<<"\tLanguage: "<<((Proggrammer*)w.get())->getProgrammingLanguage()<<endl;
//        }
//
//	}

    vector<Worker*> workers={
            new Admin("Vasia","Linux"),
            new Proggrammer("Petia","C++"),
            new Proggrammer("Ivan","Python"),
            new Proggrammer("Oleg","Ruby"),
            new Admin("Evgen","Windows")
    };

    map<Worker::Position,string> positionNames;
    positionNames[Worker::ADMIN]="Admin";
    positionNames[Worker::PROGRAMMER]="Programmer";

    for(Worker* w:workers){
        cout<<w->getName()<<endl;
        cout<<"\tPosition: "<<positionNames[w->getPosition()]<<endl;

        switch (w->getPosition()){
            case Worker::ADMIN:
                cout<<"\tOS: "<< dynamic_cast<Admin*>(w)->getOperationSystem()<<endl;
                break;
            case Worker::PROGRAMMER:
                cout<<"\tLanguage: "<<dynamic_cast<Proggrammer*>(w)->getProgrammingLanguage()<<endl;
        }
    }


    for(Worker* w:workers){
        delete w;
    }





	system("pause");
	return 0;
}
