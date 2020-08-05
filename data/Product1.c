Product1()
{

	lr_think_time(29);

	lr_start_transaction("addtocart");

	web_url("cart.php", 
		"URL=http://www.webloadmpstore.com/cart.php?event=addproduct&id=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/index.php", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	web_url("CART", 
		"URL=http://www.webloadmpstore.com/cart.php", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/cart.php?event=addproduct&id=1", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("addtocart",LR_AUTO);

	lr_think_time(12);

	web_url("Checkout>>", 
		"URL=http://www.webloadmpstore.com/checkout.php", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/cart.php", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(19);

	lr_start_transaction("checkout");

	web_url("checkout.php", 
		"URL=http://www.webloadmpstore.com/checkout.php", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/cart.php", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(28);

	web_url("server.php", 
		"URL=http://www.webloadmpstore.com/soap/server.php?wsdl", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://www.webloadmpstore.com/checkout.php", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"http://example.org/CreditCardProcess/checkValidity");

	web_custom_request("server.php_2", 
		"URL=http://www.webloadmpstore.com/soap/server.php", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://www.webloadmpstore.com/checkout.php", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\"?><soap:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\"><soap:Body><checkValidity xmlns=\"http://example.org/CreditCardProcess\"><strCardNumber>2345765</strCardNumber><strHolderID>456</strHolderID></checkValidity></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("checkout",LR_AUTO);

	return 0;
}
