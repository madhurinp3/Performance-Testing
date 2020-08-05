Product2()
{

	lr_think_time(17);

	web_url("product.php", 
		"URL=http://www.webloadmpstore.com/product.php?id=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/category.php?category_id=1", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(24);

	lr_start_transaction("addtocart");

	web_url("product.php_2", 
		"URL=http://www.webloadmpstore.com/product.php?id=8", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/category.php?category_id=1", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("button_addtocart.gif", 
		"URL=http://www.webloadmpstore.com/cart.php?event=addproduct&id=8", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/product.php?id=8", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("addtocart",LR_AUTO);

	lr_think_time(16);

	lr_start_transaction("Checkout");

	web_url("Checkout>>_2", 
		"URL=http://www.webloadmpstore.com/checkout.php", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/cart.php?event=addproduct&id=8", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(25);

	web_url("server.php_3", 
		"URL=http://www.webloadmpstore.com/soap/server.php?wsdl", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://www.webloadmpstore.com/checkout.php", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"http://example.org/CreditCardProcess/checkValidity");

	web_custom_request("server.php_4", 
		"URL=http://www.webloadmpstore.com/soap/server.php", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://www.webloadmpstore.com/checkout.php", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\"?><soap:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\"><soap:Body><checkValidity xmlns=\"http://example.org/CreditCardProcess\"><strCardNumber>12345678</strCardNumber><strHolderID>345</strHolderID></checkValidity></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("Checkout",LR_AUTO);

	return 0;
}
