#ifndef  _SHARED_NOTE
#define _SHARED_NOTE

class SharedNote
{
public:
	SharedNote(const char* note = "");
	SharedNote(const SharedNote& other);
	SharedNote& operator=(const SharedNote& other);
	SharedNote(SharedNote&& other) noexcept;
	SharedNote& operator=(SharedNote&& other) noexcept;
	~SharedNote();

private: 
	char* note;
	size_t* counter;

	void decreaseCounter();
};

#endif
