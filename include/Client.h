#ifndef CLIENT_H
#define CLIENT_H

class Client
{
	private:
		double _heureArrivee;

	public:
        Client(const Client&) = delete;

		Client(double heureArrivee);
		
		
		double heureArrivee() const;
};

#endif