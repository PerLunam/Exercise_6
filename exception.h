#pragma once

#include <stdexcept>

class RobotException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class CriticalDangerException : public RobotException
{
public:
    using RobotException::RobotException;
};

class InternalErrorException : public RobotException
{
public:
    using RobotException::RobotException;
};

class InvalidValueException : public RobotException
{
public:
    using RobotException::RobotException;
};