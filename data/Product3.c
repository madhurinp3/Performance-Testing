Product3()
{

	lr_think_time(18);

	lr_start_transaction("addtocart");

	web_url("product.php_3", 
		"URL=http://www.webloadmpstore.com/product.php?id=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/category.php?category_id=1", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_url("button_addtocart.gif_2", 
		"URL=http://www.webloadmpstore.com/cart.php?event=addproduct&id=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/product.php?id=9", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("addtocart",LR_AUTO);

	lr_think_time(16);

	lr_start_transaction("checkout");

	web_url("Checkout>>_3", 
		"URL=http://www.webloadmpstore.com/checkout.php", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/cart.php?event=addproduct&id=9", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(23);

	web_url("server.php_5", 
		"URL=http://www.webloadmpstore.com/soap/server.php?wsdl", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://www.webloadmpstore.com/checkout.php", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"http://example.org/CreditCardProcess/checkValidity");

	web_custom_request("server.php_6", 
		"URL=http://www.webloadmpstore.com/soap/server.php", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=http://www.webloadmpstore.com/checkout.php", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<?xml version=\"1.0\" encoding=\"utf-8\"?><soap:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\"><soap:Body><checkValidity xmlns=\"http://example.org/CreditCardProcess\"><strCardNumber>5674876543</strCardNumber><strHolderID>456</strHolderID></checkValidity></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("checkout",LR_AUTO);

	return 0;
}
