#include <stdexcept>
class ExcessivePieceError:public std::logic_error{
public:
    using std::logic_error::logic_error;
};
class InvalidMoveError:public std::logic_error{
public:
    using std::logic_error::logic_error;
};

