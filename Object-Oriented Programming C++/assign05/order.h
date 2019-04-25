// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"


// Put your Order class here
class Order
{
	private:
		Product product;
		int quantity;
		Customer customer;

	public:
		Order();
		Order(const Product &product, const int quantity, const Customer &customer);
		void setProduct(const Product & product) { this->product = product; }
		Product getProduct() const { return product; }
		void setQuantity(const int quantity) { this->quantity = quantity; }
		int getQuantity() const {return quantity;}
		void setCustomer(const Customer &customer) { this->customer = customer; }
		Customer getCustomer() const { return customer; }
		string getShippingZip() { return customer.getAddress().getZip(); }
		float getTotalPrice() const;
		void displayShippingLabel() const { customer.display(); }
		void displayInformation() const;
};

#endif
