using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace WebApplication1
{
    public class MainSettings
    {
        public string Text1 { get; set; }
        public string Text2 { get; set; }
        public string Header { get; set; }
        public string Footer { get; set; }
        public int RefreshCounter { get; set; }

        public MainSettings()
        {
            Text1 = string.Empty;
            Text2 = string.Empty;
            Header = string.Empty;
            Footer = string.Empty;
            RefreshCounter = 0;
        }
    }

    public class XmlSerial
    {

        public XmlSerial()
        {
            //constructor
        }
        public static MainSettings LoadSettings()
        {
            MainSettings Setting = new MainSettings();
            try
            {

                var fileName = HttpContext.Current.Server.MapPath("/App_Data/MainSettings.xml");
                if (!File.Exists(fileName))
                {
                    return Setting;
                }
                System.Xml.Serialization.XmlSerializer reader =
                new System.Xml.Serialization.XmlSerializer(typeof(MainSettings));
                System.IO.StreamReader file = new System.IO.StreamReader(fileName);
                Setting = (MainSettings)reader.Deserialize(file);
                file.Close();
                return Setting;
            }
            catch (Exception)
            {
                return Setting;
            }

        }

        public static void SaveSettings(MainSettings ObjSettings)
        {
            try
            {
                System.Xml.Serialization.XmlSerializer writer =
            new System.Xml.Serialization.XmlSerializer(typeof(MainSettings));

                var fileName = HttpContext.Current.Server.MapPath("/App_Data/MainSettings.xml");
                System.IO.FileStream file = System.IO.File.Create(fileName);

                writer.Serialize(file, ObjSettings);
                file.Close();
            }
            catch (Exception)
            {

                
            }
            
        }
    }


}

   