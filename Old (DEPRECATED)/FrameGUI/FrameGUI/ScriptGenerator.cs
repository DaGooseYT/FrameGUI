using FFLoader;
using System;
using System.ComponentModel;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace FrameGUI
{
    internal class ScriptGenerator
    {
        /// <summary>
        /// Path to SVPFlow 1 AviSynth plugin.
        /// </summary>
        private static string SVPFlow1Path { get; set; } = Directory.GetCurrentDirectory() + @"\SVP\svpflow1_av.dll";

        /// <summary>
        /// Path to SVPFlow 2 AviSynth plugin.
        /// </summary>
        private static string SVPFlow2Path { get; set; } = Directory.GetCurrentDirectory() + @"\SVP\svpflow2_av.dll";

        /// <summary>
        /// Path to FFms2 AviSynth plugin.
        /// </summary>
        private static string FFms2Path { get; set; } = Directory.GetCurrentDirectory() + @"\ffms2.dll";

        /// <summary>
        /// Generates SVPFlow parameters based on noob defined settings.
        /// </summary>
        /// <param name="worker">Instance of FFWorker.</param>
        /// <param name="ffl">Instance of FFLoader.</param>
        /// <param name="useCB">Bool of UseCB checked.</param>
        /// <param name="cancel">Cancel button.</param>
        /// <param name="maxMem">Maximum memory for AviSynth+</param>
        /// <param name="threads">Threads to use for AviSynth+</param>
        /// <param name="input">Input video file path.</param>
        /// <param name="output">Output video file path.</param>
        /// <param name="outFps">The selected output video FPS.</param>
        /// <param name="inFps">The selected input video FPS.</param>
        /// <param name="iWantIdx">Noob parameter selectedindex for smoothness.</param>
        /// <param name="gpu">Bool of UseGPU checked.</param>
        internal static void NoobHelper(BackgroundWorker worker, FFLoaderBase ffl, FrameGUI gui, bool useCB, Button cancel, int maxMem, 
            int threads, string input, string output, double outFps, double inFps, int iWantIdx, bool gpu, int oneClick)
        {
            var smooth = new StringBuilder();
            string super, analyse;

            int outFPS = (int)Math.Round(outFps);
            int inFPS = (int)Math.Round(inFps);

            if (inFPS >= outFPS)
            {
                MessageBox.Show($"The input framerate ({inFPS}fps) is equal or greater than the output framerate ({outFPS}fps). " +
                    $"If you are using the one-click method for conversion, only use input videos that are less than 60fps. Else, " +
                    $"change the output frame rate in the SVPFlow tab.", "Frame rate selection error", MessageBoxButtons.OK, 
                    MessageBoxIcon.Error);

                gui.EncodePB.ProgressText = string.Empty;
                cancel.Visible = false;
            }
            else
            {
                int findLCM = FindLCM(outFPS, inFPS);

                int denominator = findLCM / outFPS;
                int numerator = findLCM / inFPS;

                smooth.Append(@"{{rate:{{num:");
                smooth.Append(numerator);
                smooth.Append(",den:");
                smooth.Append(denominator);

                if (oneClick == 0)
                {
                    if (iWantIdx == 0)
                    {
                        smooth.Append(@"}},algo:21,mask:{{area:0}},scene:{{mode:0}}}}");
                    }
                    else if (iWantIdx == 1)
                    {
                        smooth.Append(@"}},algo:23,mask:{{area:75}},scene:{{mode:3,blend:true}}}}");
                    }
                    else
                    {
                        smooth.Append(@"}},algo:13,mask:{{area:150}},scene:{{mode:3,blend:true}}}}");
                    }

                    if (gpu)
                    {
                        analyse = @"{{vectors:3,block:{{w:8,h:8,overlap:2}},main:{{search:{{distance:0,coarse:{{distance:-10,bad:{{sad:2000}}}}}}}},refine:[{{thsad:250}}]}}";
                        super = @"{{scale:{{up:2}},gpu:1}}";
                    }
                    else
                    {
                        analyse = @"{{main:{{search:{{coarse:{{distance:0}},type:4}}}},refine:[{{thsad:250}}]}}";
                        super = @"{{scale:{{up:2}},gpu:0}}";
                    }

                    AvsGenerate(worker, ffl, useCB, cancel, maxMem, threads, input, super.Replace("{{", "{").Replace("}}", "}"),
                    analyse.Replace("{{", "{").Replace("}}", "}"), smooth.ToString().Replace("{{", "{").Replace("}}", "}"), output, oneClick);
                }
                else
                {
                    smooth.Append("}},algo:13,mask:{{area:0}},scene:{{mode:0,blend:true}}}}");
                    super = "{{pel:1,gpu:1}}";
                    analyse = "{{block:{{w:16,h:16,overlap:2}},main:{{search:{{distance:-1}}}},penalty:{{lambda:10.0,plevel:4,lsad:16000,pnew:100,pglobal:50,pzero:75,pnbour:100,prev:0}}}}";

                    AvsGenerate(worker, ffl, useCB, cancel, maxMem, threads, input, super.Replace("{{", "{").Replace("}}", "}"),
                    analyse.Replace("{{", "{").Replace("}}", "}"), smooth.ToString().Replace("{{", "{").Replace("}}", "}"), output, oneClick);
                }
            }
        }

        /// <summary>
        /// Generates a new AviSynth+ script based on user defined settings.
        /// </summary>
        /// <param name="worker">Instance of FFWorker.</param>
        /// <param name="ffl">Instance of FFLoader.</param>
        /// <param name="useCB">Bool of UseCB checked.</param>
        /// <param name="cancel">Cancel button.</param>
        /// <param name="maxMem">Maximum memory for AviSynth+</param>
        /// <param name="threads">Threads to use for AviSynth+</param>
        /// <param name="input">Input video file path.</param>
        /// <param name="super">SVSuper params.</param>
        /// <param name="analyse">SVAnalyse params.</param>
        /// <param name="smooth">SVSmooth params.</param>
        /// <param name="output">Output video file path.</param>
        internal static void AvsGenerate(BackgroundWorker worker, FFLoaderBase ffl, bool useCB, Button cancel, int maxMem, int threads, string input, 
            string super, string analyse, string smooth, string output, int oneClick)
        {
            //File path for AviSynth+ script.
            string fileOutPath = Path.GetTempPath() + @"FrameGUI\aviscript.avs";

            if (useCB || oneClick == 1)
            {
                if (File.Exists(fileOutPath))
                {
                    File.Delete(fileOutPath);
                }

                using (StreamWriter sw = File.CreateText(fileOutPath))
                {
                    sw.WriteLine($"# This file was generated using FrameGUI on {DateTime.Now}" + Environment.NewLine);
                    sw.WriteLine($"SetMemoryMax({maxMem})" + Environment.NewLine);
                    sw.WriteLine($@"LoadPlugin(""{FFms2Path}"")");
                    sw.WriteLine($@"LoadPlugin(""{SVPFlow1Path}"")");
                    sw.WriteLine($@"LoadPlugin(""{SVPFlow2Path}"")" + Environment.NewLine);
                    sw.WriteLine($@"threads={threads}" + Environment.NewLine);
                    sw.WriteLine(@"SetFilterMTMode(""DEFAULT_MT_MODE"",2)");
                    sw.WriteLine(@"SetFilterMTMode(""DirectShowSource"",3)");
                    sw.WriteLine(@"SetFilterMTMode(""SVSuper"",1)");
                    sw.WriteLine(@"SetFilterMTMode(""SVAnalyse"",1)");
                    sw.WriteLine(@"SetFilterMTMode(""SVSmoothFps"",1)" + Environment.NewLine);
                    sw.WriteLine($@"FFVideoSource(""{input}"")" + Environment.NewLine);
                    sw.WriteLine("ConvertToYV12()" + Environment.NewLine);
                    sw.WriteLine($@"super_params=""{super}""" + Environment.NewLine);
                    sw.WriteLine($@"analyse_params=""""""{analyse}""""""" + Environment.NewLine);
                    sw.WriteLine($@"smoothfps_params=""{smooth}""" + Environment.NewLine);
                    sw.WriteLine(@"super = SVSuper(super_params)");
                    sw.WriteLine(@"vectors = SVAnalyse(super, analyse_params)" + Environment.NewLine);
                    sw.WriteLine(@"SVSmoothFps(super, vectors, smoothfps_params, mt=threads)" + Environment.NewLine);
                    sw.WriteLine("Prefetch(threads)");
                    sw.Close();
                }

                if (CheckScriptNotNull(super))
                {
                    MessageHandler("Super", cancel);
                }
                else if (CheckScriptNotNull(analyse))
                {
                    MessageHandler("Analyse", cancel);
                }
                else if (CheckScriptNotNull(smooth))
                {
                    MessageHandler("Smooth", cancel);
                }
                else
                {
                    Encoder.BeginEncode(worker, ffl, useCB, input, output, oneClick);
                }
            }

            //Skip directly to encoder if AviSynth isn't used.
            else
            {
                Encoder.BeginEncode(worker, ffl, useCB, input, output, oneClick);
            }
        }

        /// <summary>
        /// Checks to make sure text of the SVP params text boxes aren't blank.
        /// </summary>
        /// <param name="text">The text of the text box.</param>
        /// <returns>True or False.</returns>
        private static bool CheckScriptNotNull(string text)
        {
            return string.IsNullOrWhiteSpace(text);
        }

        /// <summary>
        /// Throws error message if any textboxes are left blank. 
        /// </summary>
        /// <param name="box">The name of the text box.</param>
        /// <param name="cancel">Instance of the cancel button.</param>
        private static void MessageHandler(string box, Button cancel)
        {
            MessageBox.Show($"{box} text box cannot be left blank!", "Script Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

            cancel.Visible = false;
        }

        /// <summary>
        /// Finds the LCM between the input and output FPS defined by the user.
        /// </summary>
        /// <param name="outputFPS">Output video FPS</param>
        /// <param name="inputFPS">Input video FPS</param>
        /// <returns>The LCM represented in an integer.</returns>
        private static int FindLCM(int outputFPS, int inputFPS)
        {
            int numerator, denominator;

            numerator = outputFPS;
            denominator = inputFPS;

            for (int integer = 1; integer < denominator; integer++)
            {
                int multiple = numerator * integer;

                if (multiple % denominator == 0)
                {
                    return multiple;
                }
            }

            return numerator * denominator;
        }
    }
}
