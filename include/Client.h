#ifndef CLIENT_H
#define CLIENT_H

class Client
{
	private:
		const double _heureArrivee;

	public:
		Client(double heureArrivee);
		
		
		double heureArrivee() const;
};

#endif