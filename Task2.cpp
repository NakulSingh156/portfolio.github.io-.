//Business case 6 - Giving all the age groups the access of public transport.
//Data Structure Used - Linked List

void six() {
    TransportTree tree;

    // Add some transport units
    tree.insert(new TransportUnit("B001", "Bus", "Station A", "Station B", "08:30 AM", "On Time"));
    tree.insert(new TransportUnit("T001", "Train", "Station X", "Station Y", "09:00 AM", "Delayed"));
    tree.insert(new TransportUnit("B002", "Bus", "Station B", "Station C", "09:15 AM", "On Time"));
    tree.insert(new TransportUnit("T002", "Train", "Station Z", "Station A", "08:45 AM", "On Time"));

    cout << "Displaying all transport units:\n";
    tree.displayAll();

    // Search for a transport unit by ID
    string searchID = "B001";
    TransportUnit* unit = tree.search(searchID);
    if (unit != nullptr) {
        cout << "\nDetails of Transport Unit " << searchID << ":\n";
        unit->displayInfo();
    } else {
        cout << "\nTransport unit with ID " << searchID << " not found!\n";
    }

    // Update the status of a transport unit
    tree.updateStatus("B002", "Delayed");
    cout << "\nAfter updating status of B002:\n";
    tree.displayAll();
 
}
