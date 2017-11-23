package com;

import javax.servlet.*;

public class Listener implements ServletContextListener{

	private static int count = 0;
	public void contextDestroyed(ServletContextEvent arg0) {
		count--;
		
	}

	public void contextInitialized(ServletContextEvent arg0) {
		count++;
		
	}

	public static int getCount()
	{
	    return count;
	}
}
