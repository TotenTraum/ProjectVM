#pragma once
class Command{
public:
	virtual void operator()() = 0;
};

class IncCommand :public Command {
public:
	void operator()();
};

class AddCommand :public Command {
public:
	void operator()();
};

class SubCommand :public Command {
public:
	void operator()();
};

class MulCommand :public Command {
public:
	void operator()();
};

class DivCommand :public Command {
public:
	void operator()();
};

class MovCommand :public Command {
public:
	void operator()();
};