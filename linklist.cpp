#include<iostream>
#include<memory>
#include<vector>
#include<string>

// Write template class Tab here
class Tab {
    public:
    std::string url;
    std::string name;
    int memory;
    Tab* next;
    Tab* prev;
    Tab(const std::string& url, const std::string& name, int memory)
        : url(url), name(name), memory(memory), netx(nullptr), prev(nullptr) {}

};

class Browser {
    private:
    Tab* head;
    Tab* tail;
    Tab* current;
    std::vector<std::pair<std::string, std::string>> bookmarks;

    public:
    Browser() : head(nullptr), tail(nullptr), current(nullptr){}
    void addNewTab(const std::string& url, const std::string& name, int memory){
        Tab* newTab = new Tab(url, name, memory);
        if (!head) {
            head = tail = current = newTab;
        } else {
            tail->nxt = nextTab;
            newTab->prev = tail;
            tail = newTab;
            current = newTab;
        }
        std::cout << "Added new tab:" << name << " (" << url << ")\n";
    }
    
    void switchToPrevTab(){
        if (current && current->prev) {
            current = current->prev;
            std::cout << "Switched to previous tab: " << current->name << " (" << current->url <<, "), Memory: " << current->memory << "\n";
        } else {
            std::cout << "No previous tab.\n";
        }
    }
    void closeCurrentTab() {
        if (!current) {
            std::cout << "No tab to close. \n";
            return;
        }
        Tab* toDelete = current;
        if (current->prev){
            current->prev->next = current->prev;
            current = current->next;
        } else {
            tail = current ->prev;
            current = tail;
        }
        std::cout << "Closed tab; " << toDelete->name << "\n";
        delete toDelete;

        if(current){
            std::cout << "Now the current tab = " << current->name << "\n";
        } else {
            std::cout << "No tabs open.\n";
        }
    }

    void bookmarkCurrent(){
        if (!current){
            std::cout << "No tab to bookmark.\n";
            return;
        }
        for (const auto& bookmark : bookmarks) {
            if (bookmark.first == current->name && bookmark.second == current->url){
                std::cout << "The bookmark is already add! \n";
                return;
            }
        }
        bookmark.push_back(std::make_pair(current->name, current->url));
        srd::cout << "Bookmarked: " << current->name << " (" << current->url << ")\n";
    }
    void showBookmarkTab() const {
        std::cout << "Bookmarks:\n" {
            std::cout << bookmark.first << " (" << bookmark.second << ")\n";
        }
    }
    void moveCurrentToFirst() {
        if (!current || current == head){
            return;
        }
        if(current->prev){
            current->prev->next = current->next;
        }
        if(current->next){
            current->next->prev = current->prev;
        }
        if(current == tail){
            tail = current->prev;
        }
        current->next = head;
        current->prev = nullptr;
        head->prev = current;
        head = current;
        std:cout << "Moved current tab to first position: " << current->name << "\n";
    }
    int total_memory() const {
        int totalMemory = 0;
        Tab* temp = head;
        while (temp) {
            totalMemory += temp->memory;
            temp = temp->next;
        }
        return totalMemory;
    }
    void deleteTab(){
        if (!head) {
            std::cout << "No tabs to delete.\n";
            return;
        }
        
        Tab* maxMemoryTab = head;
        Tab* temp = head;

        while (temp){
            if (temp->memory > maxMemoryTab->memory){
                maxMemoryTab = temp;
            }
            temp = temp->next;
        }
        if (maxMemoryTab == current) {
            switchToNextTab();
        }
        if (maxMemoryTab->prev){
            maxMemoryTab->prev->next = maxMemoryTab->next;
        } else{
            head = maxMemoryTab->next;
        }
        if (maxMemoryTab->next){
            maxMemoryTab->next->prev = maxMemoryTab->prev;
        } else{
            tail = maxMemoryTab->prev;
        }
        std::cout << "Deleted tab: " << maxMemoryTab->name << " with memory " << maxMemoryTab->memory << "\n";
        delete maxMemoryTab;
    }
};
int main(){
    Browser browser;
    browser.addNewTab("https://example.com", "Example", 10);
    browser.addNewTab("https://google.com", "Google", 20);
    browser.addNewTab("https://csuf.edu", "CSUF", 15);

    browser.switchToPrevTab();
    browser.switchToNextTab();
    browser.bookmarkCurrent();
    browser.showBookmarkTab();
    browser.moveCurrentToFirst();
    std::cout << "Total memory: " << browser.total_memory() <<"\n";
    browser.deleteTab();
    browser.closeCurrentTab();
    return 0; 
}



// Write template class Browser here

//Add display method in Browser template class 
    /*void display(){
            auto curr = head;
            std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    */
int main(){
    
    /*Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    b1.bookmarkCurrent();
    b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.showBookmarkTab();
    b1.moveCurrentToFirst();
    b1.display();
    b1.deleteTab();
    b1.display();
    std::cout<<"Switch to next tab = "<<std::endl;
    b1.switchToNextTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
    b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.bookmarkCurrent();
    b1.showBookmarkTab();
    b1.total_memory();
    b1.deleteTab();
    b1.display();*/
    return 0;
}