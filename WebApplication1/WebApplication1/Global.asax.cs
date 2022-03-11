using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Optimization;
using System.Web.Routing;
using System.Web.Security;
using System.Web.SessionState;


namespace WebApplication1
{
    public class Global : HttpApplication
    {
        void Application_Start(object sender, EventArgs e)
        {
            // Code that runs on application startup
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);
            MainSettings Setting = XmlSerial.LoadSettings();
            Application.Add("Settings", Setting);
        }


        void Session_Start(object sender, EventArgs e)
        {

            if (Application["visitor"] == null)
            {
                Application.Add("visitor", 1);
            }
            else
            {
                try
                {
                    int iCount = Convert.ToInt32(Application["visitor"]);
                    iCount++;
                    MainSettings Set = (MainSettings)Application["Settings"];
                    Set.VisitorNo += iCount;
                    XmlSerial.SaveSettings(Set);
                    Application["visitor"] = Set.VisitorNo.ToString();
                }
                catch (Exception)
                {

                    
                }
                
            }
        }
            

    }
}