// USBConnection.h

#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <stack>
#include <memory>

class USBConnection {
private:
    int ID;  // Unique ID for each USB connection

    // Constructor is private to restrict object creation
    explicit USBConnection(int id) : ID(id) {}

public:
    // Destructor returns the ID to the available stack
    ~USBConnection() {
        ids.push(ID);
    }

    // Function to get the ID of the connection
    int get_id() const {
        return ID;
    }

    // Static function to create a new USB connection
    static USBConnection* CreateUsbConnection() {
        if (!ids.empty()) {
            int id = ids.top();
            ids.pop();
            return new USBConnection(id);
        } else {
            return nullptr;
        }
    }

    // Static stack to keep track of available IDs
    static std::stack<int> ids;
};

// Initialize the static stack with IDs 3, 2, 1 (in reverse order)
std::stack<int> USBConnection::ids({3, 2, 1});

#endif // USBCONNECTION_H
