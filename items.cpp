
#include <iostream>
#include "fstream"
#include "sstream"
#include "algorithm"
#include "vector"

#define FILENAME "items.csv"

using namespace std;

struct Item  {
	int item_id;
	string item_name;
	int item_quantity;
	string reg_date;
};


void addItem(const Item &item)	{
	ofstream file(FILENAME, ios::app);
	if(file.is_open()){
		file << item.item_id << " " << item.item_name << " " << item.item_quantity << " " << item.reg_date << endl;
		cout << "item saved successfully" << endl;
		file.close();
	} else {
		cerr << " Failed to open the file " << FILENAME << endl;
	}
	
}


void listItems() {
    ifstream file(FILENAME);
    vector<Item> items;
    string line;
    string item_id, item_name, item_quantity, reg_date;

    if (file.is_open()) {
        while (getline(file, line)) {
            // convert to string stream
            istringstream ss(line);
            // store stream values to corresponding variables
            if (ss >> item_id >> item_name >> item_quantity >> reg_date) {
                Item itm = {
                        stoi(item_id),
                        item_name,
                        stoi(item_quantity),
                        reg_date
                };
                items.push_back(itm);
            } else {
                cerr << "Invalid record : " << line << endl;
            }
        }
        if (!items.empty()) {
            for (auto &item: items) {
                cout << "Item ID: " << item.item_id << "\t" << "Item Name :" << item.item_name << "\t"
                     << "Quantity :" << item.item_quantity << "\t" << "Reg Date :"
                     << item.reg_date << endl;
            }
        } else {
            cout << "No items found in " << FILENAME << endl;
        }
        file.close();
    } else {
        cerr << "failed to open the file : " << FILENAME << endl;
    }
}


int main(){
	string command, user_input, item_id, item_name , item_quantity, reg_date; 
	while(true){
		cout << " Enter the command " << endl;
		getline(cin, user_input);
		istringstream ss(user_input);
		ss >> command;
		
		if(command == "itemadd"){
			if (ss >> item_id >> item_name >> item_quantity >> reg_date) {
				Item item  =  {
					stoi(item_id),
					item_name,
					stoi(item_quantity),
					reg_date
				};
			addItem(item);
		    } else {
            cerr << "Invalid input format" << endl;
            }
		} else if(command == "itemslist") {
			listItems();
		} else if(command == "help"){
			cout << "==================================================================================================" << endl;
			cout << "==================================================================================================" << endl;
			cout << "       Enter itemadd <item_id> <item_name> <item_quantity> <reg_date> to add an item"  << endl;
			cout << "       Example itemadd 2 apple 1 2024-12-31" << endl;
			cout << "       Enter itemslist to list the items" << endl;
			cout << "       Enter exit to exit the program" << endl;
			cout << "       Enter help for help "  << endl;
			cout << "====================================================================================================" << endl;
			cout << "====================================================================================================" << endl;
			
		} else if(command == "exit"){
		    cout << "Quitting the program..." << endl;
            exit(0);
        } else {
            cerr << "Invalid Command" << endl;
        }
	}
}