void five() {
    PublicTransport transport;

    // Adding sections for different age groups
    transport.addSection("Children", 20);
    transport.addSection("Adults", 50);
    transport.addSection("Senior Citizens", 15);

    // Display the sections of the transport
    cout << "Current Transport Sections: " << endl;
    transport.displaySections();

    // Assign passengers to different age groups
    transport.assignPassengersToAgeGroup("Children", 5);
    transport.assignPassengersToAgeGroup("Adults", 10);
    transport.assignPassengersToAgeGroup("Senior Citizens", 3);
    transport.assignPassengersToAgeGroup("Children", 25); // This should show a capacity issue
    
}

// Class to represent a transport unit (e.g., Bus, Train)
class TransportUnit {
public:
    string id;
    string type; // Bus, Train, etc.
    string currentLocation;
    string nextStop;
    string scheduledTime;
    string status; // On time, Delayed, etc.

    TransportUnit(string id, string type, string currentLocation, string nextStop, string scheduledTime, string status) {
        this->id = id;
        this->type = type;
        this->currentLocation = currentLocation;
        this->nextStop = nextStop;
        this->scheduledTime = scheduledTime;
        this->status = status;
    }

    // Display transport details
    void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Type: " << type << endl;
        cout << "Current Location: " << currentLocation << endl;
        cout << "Next Stop: " << nextStop << endl;
        cout << "Scheduled Time: " << scheduledTime << endl;
        cout << "Status: " << status << endl;
    }
};

// Node of a Binary Search Tree to store TransportUnits
class TransportNode {
public:
    TransportUnit* transportUnit;
    TransportNode* left;
    TransportNode* right;

    TransportNode(TransportUnit* transportUnit) {
        this->transportUnit = transportUnit;
        left = right = nullptr;
    }
};

// Binary Search Tree for managing the transport units
class TransportTree {
private:
    TransportNode* root;

    // Helper function for insertion
    TransportNode* insert(TransportNode* node, TransportUnit* transportUnit) {
        if (node == nullptr) {
            return new TransportNode(transportUnit);
        }

        // Compare by transport unit ID
        if (transportUnit->id < node->transportUnit->id) {
            node->left = insert(node->left, transportUnit);
        } else if (transportUnit->id > node->transportUnit->id) {
            node->right = insert(node->right, transportUnit);
        }

        return node;
    }

    // Helper function for in-order traversal
    void inOrder(TransportNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            node->transportUnit->displayInfo();
            inOrder(node->right);
        }
    }

    // Helper function to search for a transport unit by ID
    TransportNode* search(TransportNode* node, string id) {
        if (node == nullptr || node->transportUnit->id == id) {
            return node;
        }

        if (id < node->transportUnit->id) {
            return search(node->left, id);
        }
        return search(node->right, id);
    }

public:
    TransportTree() {
        root = nullptr;
    }

    // Insert a transport unit
    void insert(TransportUnit* transportUnit) {
        root = insert(root, transportUnit);
    }

    // Display all transport units in sorted order by ID
    void displayAll() {
        inOrder(root);
    }

    // Search for a transport unit by ID
    TransportUnit* search(string id) {
        TransportNode* result = search(root, id);
        if (result != nullptr) {
            return result->transportUnit;
        }
        return nullptr;
    }

    // Update transport status
    void updateStatus(string id, string newStatus) {
        TransportUnit* unit = search(id);
        if (unit != nullptr) {
            unit->status = newStatus;
        } else {
            cout << "Transport unit with ID " << id << " not found!" << endl;
        }
    }
};
