#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include <string>
class Cure : public AMateria {
public:
	Cure(void);
	~Cure(void);
	Cure(Cure const& c);
	Cure& operator=(Cure const& c);
	std::string const& getType() const;
	AMateria* clone() const;
	void use(ICharacter& target);
};
#endif
