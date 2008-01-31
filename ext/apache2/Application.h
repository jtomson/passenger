#ifndef _PASSENGER_APPLICATION_H_
#define _PASSENGER_APPLICATION_H_

#include <sys/types.h>
#include <boost/shared_ptr.hpp>
#include <string>

namespace Passenger {

using namespace std;
using namespace boost;

// TODO: write better documentation
class Application {
private:
	string appRoot;
	pid_t pid;
	int reader, writer;
public:
	Application(const string &theAppRoot, pid_t pid, int reader, int writer) {
		appRoot = theAppRoot;
		this->pid = pid;
		this->reader = reader;
		this->writer = writer;
	}
	
	~Application() {
		closeReader();
		closeWriter();
	}
	
	string getAppRoot() const {
		return appRoot;
	}
	
	pid_t getPid() const {
		return pid;
	}
	
	int getReader() const {
		return reader;
	}
	
	int getWriter() const {
		return writer;
	}
	
	void closeReader() {
		if (reader != -1) {
			close(reader);
			reader = -1;
		}
	}
	
	void closeWriter() {
		if (writer != -1) {
			close(writer);
			writer = -1;
		}
	}
};

typedef shared_ptr<Application> ApplicationPtr;

} // namespace Passenger

#endif /* _PASSENGER_APPLICATION_H_ */
