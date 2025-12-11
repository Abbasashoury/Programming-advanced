#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\ResourceManager.h"
using namespace std;

class ResourceManager
{
private:
    vector<Resource> resources;
    static int totalResources;

public:
    void addResource(const Resource &) {}
    void searchResourceByName(const string &) {}
    void printAllSchedules() {}
};