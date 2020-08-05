Login()
{

	web_url("www.webloadmpstore.com", 
		"URL=http://www.webloadmpstore.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/media/images/header_bg.gif", ENDITEM, 
		"Url=/media/images/th.gif", ENDITEM, 
		"Url=/media/images/border_bg_l.gif", ENDITEM, 
		LAST);

	lr_think_time(17);

	lr_start_transaction("Login");

	web_url("LOGIN", 
		"URL=http://www.webloadmpstore.com/login.php", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(12);

	web_submit_data("login.php", 
		"Action=http://www.webloadmpstore.com/login.php", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://www.webloadmpstore.com/login.php", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=login", "Value=shiva", ENDITEM, 
		"Name=password", "Value=sunmoon", ENDITEM, 
		"Name=sessionID", "Value=webloadmpstore.183.83.143.3.91873d7b7d7756ecfa25ac75f3d6e3dc", ENDITEM, 
		"Name=event", "Value=login", ENDITEM, 
		"Name=Submit", "Value=Login", ENDITEM, 
		EXTRARES, 
		"Url=/media/images/th.gif", "Referer=http://www.webloadmpstore.com/index.php", ENDITEM, 
		"Url=/media/images/header_bg.gif", "Referer=http://www.webloadmpstore.com/index.php", ENDITEM, 
		"Url=/media/images/border_bg_l.gif", "Referer=http://www.webloadmpstore.com/index.php", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	return 0;
}
