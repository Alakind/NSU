#ifndef FUNCTIONS_LAB1
#define FUNCTIONS_LAB1

struct copy {
    std::string name;
    int timer;
} typedef copy;

std::vector<copy> copies;

#define PORT 8080
#define MAXLEN 1000
#define TIMER 10

void describe_proccess(std::string name,
    int socked_desc,
    struct sockaddr* cliend_adress,
    const size_t client_adress_len)
{
    //std::cout << "sending..." << std::endl;
    sendto(socked_desc, name.c_str(), name.length(), 0, cliend_adress, client_adress_len);
}

std::vector<copy> update_copies(std::vector<copy> copies, std::string new_name) {
    std::vector<int> to_delete;
    bool found = false;
    for (unsigned int i = 0; i < copies.size(); i++) {
        if (copies[i].name == new_name) {
            copies[i].timer = TIMER;
            found = true;
        }
        
        if (copies[i].timer < 1) {
            to_delete.push_back(i);
        }

        copies[i].timer--;
    }
    if (!found) {
        copies.push_back({new_name, TIMER});    
    }

    for (unsigned int i = 0; i < to_delete.size(); i++) {
        copies.erase(copies.begin() + to_delete[i] - i);
    }

    return copies;
}
std::vector<copy> update_copies(std::vector<copy> copies) {
    std::vector<int> to_delete;
    for (unsigned int i = 0; i < copies.size(); i++) {
        if (copies[i].timer < 1) {
            to_delete.push_back(i);
        }
        copies[i].timer--;
    }

    for (unsigned int i = 0; i < to_delete.size(); i++) {
        copies.erase(copies.begin() + to_delete[i] - i);
    }

    return copies;
}

void print_copies(std::vector<copy> copies) {
    if (copies.size() == 0) {
        return;
    }

    std::cout << "Proccesses online:" << std::endl;
    for (unsigned int i = 0; i < copies.size(); i++) {
        std::cout << " " << copies.at(i).name << std::endl;
    }

    std::cout << "---------------------------" << std::endl;
}

#endif //FUNCTIONS_LAB1
