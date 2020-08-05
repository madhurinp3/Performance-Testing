Demo()
{

	lr_think_time(26);

	lr_start_transaction("Demos");

	web_url("category.php", 
		"URL=http://www.webloadmpstore.com/category.php?category_id=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/checkout.php", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Demos",LR_AUTO);

	return 0;
}
