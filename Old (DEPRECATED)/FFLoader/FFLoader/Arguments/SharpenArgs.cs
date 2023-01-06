using System.Globalization;

namespace FFLoader.Arguments
{
    internal class SharpenArgs
    {
        /// <summary>
        /// The selected output video sharpening level. 
        /// </summary>
        /// <param name="sharpen">The sharpening strength.</param>
        /// <param name="resEnabeled">Determins if resultion is also being changed for the purposes of correct formatting; bool format.</param>
        /// <returns>String representation of the argument.</returns>
        internal static string SharpenResEnabled(float sharpen, bool resEnabeled, bool fps)
        {
            string sh = sharpen.ToString();

            if (sharpen.ToString().Contains(","))
            {
                sh = sh.Replace(",", ".");
            }

            if (resEnabeled || fps)
            {
                return string.Format($@" , unsharp=5:5:{sh}""", CultureInfo.InvariantCulture);
            }
            else
            {
                return string.Format($@" -vf unsharp=5:5:{sh}", CultureInfo.InvariantCulture);
            }
        }
    }
}
