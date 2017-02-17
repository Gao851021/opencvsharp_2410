﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using OpenCvSharp;
using OpenCvSharp.Extensions;
using SampleBase;

namespace CStyleSamplesCS
{
    /// <summary>
    /// System.Windows.Media.Imaging.BitmapSourceへの変換
    /// </summary>
    class ConvertToBitmapSource
    {
        public ConvertToBitmapSource()
        {
            BitmapSource bs = null;

            // OpenCVによる画像処理 (Threshold)
            using (IplImage src = new IplImage(FilePath.Image.Lenna, LoadMode.GrayScale))
            using (IplImage dst = new IplImage(src.Size, BitDepth.U8, 1))
            {
                src.Smooth(src, SmoothType.Gaussian, 5);
                src.Threshold(dst, 0, 255, ThresholdType.Otsu);
                // IplImage -> BitmapSource
                bs = dst.ToWriteableBitmap();
                //bs = BitmapSourceConverter.ToBitmapSource(dst);
            }

            // WPFのWindowに表示してみる
            Image image = new Image { Source = bs };
            Window window = new Window
            {
                Title = "from IplImage to BitmapSource",
                Width = bs.PixelWidth,
                Height = bs.PixelHeight,
                Content = image
            };

            Application app = new Application();
            app.Run(window);
        }
    }
}
