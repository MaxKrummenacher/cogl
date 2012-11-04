/* This file has been generated by parse-gir.py, do not hand edit */
using System;
using System.Runtime.InteropServices;

namespace Cogl
{
    public partial class OnScreen
    {
        [DllImport("cogl2.dll")]
        public static extern bool cogl_onscreen_get_resizable(IntPtr o);

        public bool GetResizable()
        {
            return cogl_onscreen_get_resizable(handle);
        }

        [DllImport("cogl2.dll")]
        public static extern void cogl_onscreen_hide(IntPtr o);

        public void Hide()
        {
            cogl_onscreen_hide(handle);
        }

        [DllImport("cogl2.dll")]
        public static extern void cogl_onscreen_remove_resize_handler(IntPtr o, uint id);

        public void RemoveResizeHandler(uint id)
        {
            cogl_onscreen_remove_resize_handler(handle, id);
        }

        [DllImport("cogl2.dll")]
        public static extern void cogl_onscreen_remove_swap_buffers_callback(IntPtr o, uint id);

        public void RemoveSwapBuffersCallback(uint id)
        {
            cogl_onscreen_remove_swap_buffers_callback(handle, id);
        }

        [DllImport("cogl2.dll")]
        public static extern void cogl_onscreen_set_resizable(IntPtr o, bool resizable);

        public void SetResizable(bool resizable)
        {
            cogl_onscreen_set_resizable(handle, resizable);
        }

        [DllImport("cogl2.dll")]
        public static extern void cogl_onscreen_set_swap_throttled(IntPtr o, bool throttled);

        public void SetSwapThrottled(bool throttled)
        {
            cogl_onscreen_set_swap_throttled(handle, throttled);
        }

        [DllImport("cogl2.dll")]
        public static extern void cogl_onscreen_show(IntPtr o);

        public void Show()
        {
            cogl_onscreen_show(handle);
        }

        [DllImport("cogl2.dll")]
        public static extern void cogl_onscreen_swap_buffers(IntPtr o);

        public void SwapBuffers()
        {
            cogl_onscreen_swap_buffers(handle);
        }

    }
}