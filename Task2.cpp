//Business case 6 - Giving all the age groups the access of public transport.
//Data Structure Used - Linked List

class PublicTransport {
private:
    TransportSection* head; // Head pointer to the linked list of sections

public:
    PublicTransport() {
        head = nullptr;
    }

    // Function to add a section for a particular age group
    void addSection(string group, int capacity) {
        TransportSection* newSection = new TransportSection(group, capacity);
        if (head == nullptr) {
            head = newSection; // If the list is empty, make the new section the head
        } else {
            TransportSection* temp = head;
            // Traverse to the last section in the linked list
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // Link the new section at the end
            temp->next = newSection;
        }
    }

    // Function to display the sections of the transport and their capacities
    void displaySections() {
        if (head == nullptr) {
            cout << "No sections available." << endl;
            return;
        }
        
        TransportSection* temp = head;
        while (temp != nullptr) {
            cout << "Age Group: " << temp->ageGroup << " | Capacity: " << temp->capacity << endl;
            temp = temp->next;
        }
    }

    // Function to assign passengers to a particular age group
    void assignPassengersToAgeGroup(string group, int passengers) {
        TransportSection* temp = head;
        bool found = false;

        while (temp != nullptr) {
            if (temp->ageGroup == group) {
                found = true;
                if (temp->capacity >= passengers) {
                    temp->capacity -= passengers;
                    cout << passengers << " passengers assigned to the " << group << " section." << endl;
                } else {
                    cout << "Not enough capacity in the " << group << " section. Available capacity: " << temp->capacity << endl;
                }
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Age group " << group << " not found in the transport system." << endl;
        }
    }

    // Destructor to free memory allocated for the linked list
    ~PublicTransport() {
        TransportSection* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

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
