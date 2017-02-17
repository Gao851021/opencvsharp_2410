﻿using System;
using System.Drawing;
using System.Windows.Forms;
using OpenCvSharp;
using OpenCvSharp.UserInterface;
using SampleBase;

namespace CStyleSamplesCS
{
    /// <summary>
    /// PictureBoxIpl sample
    /// </summary>
    class PictureBoxIplSample
    {
        public PictureBoxIplSample()
        {
            using (IplImage img = new IplImage(FilePath.Image.Fruits, LoadMode.Color))
            {
                using (Form form = new Form() { ClientSize = new Size(img.Width, img.Height), Text = "PictureBoxIpl Sample" })  
                using (PictureBoxIpl pbi = new PictureBoxIpl())
                {
                    pbi.ImageIpl = img;
                    pbi.ClientSize = form.ClientSize;
                    form.Controls.Add(pbi);

                    Application.Run(form);
                }
            }

        }

    }
}
