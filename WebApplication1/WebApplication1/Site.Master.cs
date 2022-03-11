using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class SiteMaster : MasterPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            try
            {
                MainSettings Setting = (MainSettings)Application["Settings"];
                Header_Text.Text = Setting.Header;
                LabelFootertext.Text = Setting.Footer;
                Label_Footer.Text = "You are visitor No:" + Application["visitor"].ToString();
                if (Session["UserId"] != null)
                {
                    btn_login.Visible = false;
                    Button_logout.Visible = true;
                }
            }
            catch (Exception)
            {

               
            }
           
        }

        protected void btn_login_Click(object sender, EventArgs e)
        {       
            
                Response.Redirect("/Login.aspx");
           
        }

        protected void Button_logout_Click(object sender, EventArgs e)
        {
            Session.Remove("UserId");
            Response.Redirect("/Default.aspx");
        }
    }
}