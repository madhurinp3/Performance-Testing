Logout()
{

	lr_think_time(27);

	lr_start_transaction("Logout");

	web_url("login.php_2", 
		"URL=http://www.webloadmpstore.com/login.php?event=logout", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/checkout.php", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	return 0;
}