using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class AdminPannel : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

            if(Session["UserId"]==null)
            {
                Response.Redirect("/Default.aspx");
            }
            else
            {

                if (!Page.IsPostBack)
                {
                    try
                    {
                        MainSettings Settings = (MainSettings)Application["Settings"];
                        Text1.Text = Settings.Text1;
                        Text2.Text = Settings.Text2;
                        Header1.Text = Settings.Header;
                        Header2.Text = Settings.Footer;
                    }
                    catch (Exception)
                    {

                        
                    }
                    
                }
            }

        }

        protected void ButtonSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                MainSettings Setting = (MainSettings)Application["Settings"];
                Setting.Text1 = Text1.Text;
                Setting.Text2 = Text2.Text;
                Setting.Header = Header1.Text;
                Setting.Footer = Header2.Text;
                XmlSerial.SaveSettings(Setting);
                Application["Settings"] = Setting;
                Response.Redirect("Default.aspx");
            }
            catch (Exception)
            {

            }
            
        }
    }
}